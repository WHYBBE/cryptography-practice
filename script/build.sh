#!/bin/bash
cd build
rm -rf release
mkdir release
cd release

cmake ../.. -DCMAKE_INSTALL_PREFIX="../.." -DCMAKE_BUILD_TYPE=Release
