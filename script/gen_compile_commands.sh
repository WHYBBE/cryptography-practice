#!/bin/bash
cd build
rm -rf prompt
mkdir prompt
cd prompt

cmake ../.. -DCMAKE_EXPORT_COMPILE_COMMANDS=YES

cp compile_commands.json ../..
