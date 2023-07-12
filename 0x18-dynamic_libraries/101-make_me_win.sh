#!/bin/bash
gcc -shared -fPIC -o nrandom.so ./0x18.c
export LD_PRELOAD=./nrandom.so