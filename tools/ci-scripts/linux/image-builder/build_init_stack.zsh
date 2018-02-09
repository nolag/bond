#!/bin/zsh

set -eux

# This script builds the dependencies that gbc and gbc-tests use into the
# image so that we build these once.
#
# Stack is smart enough to build any missing dependencies, so if the
# pre-built dependencies in the image no longer match what bond.cabal
# specifics, we won't get an incorrect build, just a slower one.
#
# Stack doesn't have a native way of moving the .stack-work directory
# outside of the build directory, so we have to play symlink tricks here and
# also right before we perform the actual build. See also:
# https://github.com/commercialhaskell/stack/issues/1731

BUILD_SOURCE_COMMIT=$1

if [[ -z "$BUILD_SOURCE_COMMIT" ]]; then
    echo "Required BUILD_SOURCE_COMMIT not given. Won't be able to download source files." > 2
    exit 1
fi

SAVED_STACK_WORK=/opt/stack/stack-work/
TEMP_COMPILER_PATH=/tmp/bond-only-compiler/

mkdir -p "$SAVED_STACK_WORK"
mkdir -p "$TEMP_COMPILER_PATH"

pushd "$TEMP_COMPILER_PATH"

# Download the minimal files that Stack needs to figure out the dependent
# packages.
STACK_FILES=('bond.cabal' 'stack.yaml')
# This URI specific to the format the GitHub uses and is tied to the main
# repository. If we need to support arbitrary repositories later, we'll
# probably want to shallow clone the repository and sparse checkout just the
# compiler/ directory.
DOWNLOAD_URI_FORMAT='https://raw.githubusercontent.com/Microsoft/bond/%s/compiler/%s'
for FILE in $STACK_FILES; do
    local FILE_URI=`printf "$DOWNLOAD_URI_FORMAT" "$BUILD_SOURCE_COMMIT" "$FILE"`
    wget $FILE_URI
done

# We can't use --work-dir to move this outside the current directory, so we
# use a symlink instead.
ln -s "$SAVED_STACK_WORK" .stack-work

stack setup
stack build --only-dependencies bond:gbc bond:gbc-tests

popd
rm -rf "$TEMP_COMPILER_PATH"
