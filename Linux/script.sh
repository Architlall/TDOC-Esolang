#!/bin/bash

cd ..
cd Main
make
./tokenizer $1
g++ output.c -o output
./output
rm output output.c