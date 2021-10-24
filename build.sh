#!/bin/bash

set -e

./clean-sdk.sh

pushd external_libs
   ./build.sh
popd
