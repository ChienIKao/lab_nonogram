#!/bin/bash

g++ -c src/Description.cpp
g++ -o temp nonogram.cpp Description.o

./temp