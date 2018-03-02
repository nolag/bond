#include "allocators.h"

#include "helloworld_with_template_alloc_grpc.h"
#include "helloworld_with_template_alloc_types.h"

#include <bond/ext/grpc/io_manager.h>
#include <bond/ext/grpc/server.h>
#include <bond/ext/grpc/server_builder.h>
#include <bond/ext/grpc/thread_pool.h>
#include <bond/ext/grpc/unary_call.h>
#include <bond/ext/grpc/wait_callback.h>

#include <chrono>
#include <functional>
#include <iostream>
#include <memory>
#include <string>

using grpc::Channel;
using grpc::ServerBuilder;
using grpc::Status;

using namespace helloworld_with_template_alloc;

// Logic and data behind the server's behavior.
class GreeterServiceImpl final : public Greeter<ExampleAllocator>::Service
{
    void SayHello(
        bond::ext::gRPC::unary_call<
            bond::bonded<HelloRequest<ExampleAllocator>>,
            HelloReply<ExampleAllocator>> call) override
    {
        HelloRequest<ExampleAllocator> request = call.request().Deserialize();

        HelloReply<ExampleAllocator> reply;
        reply.message = "hello " + request.name;

        call.Finish(reply);
    }
};

int main()
{
    auto ioManager = std::make_shared<bond::ext::gRPC::io_manager>();
    auto threadPool = std::make_shared<bond::ext::gRPC::thread_pool>();

    GreeterServiceImpl service;

    bond::ext::gRPC::server_builder builder;
    builder.SetThreadPool(threadPool);
    const std::string server_address("127.0.0.1:50051");
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<bond::ext::gRPC::server> server(builder.BuildAndStart());

    // This proves that the client and server can use different allocators
    Greeter<std::allocator>::Client greeter(
        grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()),
        ioManager,
        threadPool);

    const std::string user("world");

    HelloRequest<> request;
    request.name = user;

    bond::ext::gRPC::wait_callback<HelloReply<>> cb;
    greeter.AsyncSayHello(request, cb);

    bool waitResult = cb.wait_for(std::chrono::seconds(10));

    if (!waitResult)
    {
        std::cout << "timeout ocurred";
        return 1;
    }
    else if (!cb.status().ok())
    {
        std::cout << "request failed";
        return 1;
    }

    HelloReply<> reply;
    cb.response().Deserialize(reply);

    if (reply.message.compare("hello world") != 0)
    {
        std::cout << "Wrong response: " << reply.message;
        return 1;
    }

    std::cout << "Correct response: " << reply.message;

    return 0;
}
