#!/bin/bash

clear
make DEBUG=1
gcc -g -fsanitize=address test.c -I includes libftprintf.a -o test
./test
