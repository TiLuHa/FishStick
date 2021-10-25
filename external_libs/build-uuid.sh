#!/bin/bash

set -e

mkdir -vp $SDK_INC/uuid
cp -v stduuid/include/uuid.h $SDK_INC/uuid/uuid.hpp
