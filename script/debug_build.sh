#!/bin/bash
cd build
rm -rf debug
mkdir debug
cd debug

cmake ../.. -DCMAKE_INSTALL_PREFIX="../.." -DCMAKE_BUILD_TYPE=Debug
