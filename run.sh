#!/bin/bash

g++ -c src/Description.cpp src/Line.cpp -g
g++ -o temp nonogram.cpp Description.o Line.o

