#!/bin/bash

export PROJECT_ROOT=$(pwd)
export SDK=$PROJECT_ROOT/SDK
export SDK_LIB=$SDK/lib
export SDK_BIN=$SDK/bin
export SDK_INC=$SDK/inc

mkdir -p $SDK
mkdir -p $SDK_LIB
mkdir -p $SDK_BIN
mkdir -p $SDK_INC
