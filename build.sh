#!/bin/bash
BUILD_TYPE=${CMAKE_BUILD_TYPE:-Debug}
INSTALL=`pwd`
mkdir -p build
pushd build
cmake .. -DCMAKE_INSTALL_PREFIX:PATH=$INSTALL -DCMAKE_BUILD_TYPE=$BUILD_TYPE
make install
popd
