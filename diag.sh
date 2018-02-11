#!/bin/bash
set -eux

which zsh || echo no zsh
which docker || echo no docker
which az || echo no az

az acr repository show-tags \
   --name bondciimages \
   --repository ubuntu-1604
