#!/bin/bash

clang++ -std=c++14 -shared -I. -o liba.so liba.cpp
clang++ -std=c++14 -shared -I. -o libb.so libb.cpp
clang++ -std=c++14 -ldl -o main main.cpp
