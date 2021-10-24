#!/bin/bash

set -e

pushd mailio
   mkdir -p build
   
   pushd build
      cmake -DMAILIO_BUILD_SHARED_LIBRARY=0 ../
      make
      mkdir -vp $SDK_INC/mailio
      cp -v export.hpp $SDK_INC/mailio
      cp -v libmailio.a $SDK_LIB
   popd
   
   cp -vr include/mailio $SDK_INC
   
   rm -r build
popd
