#!/bin/bash

clear
make DEBUG=1
gcc -g -fsanitize=address test.c -I lib ft_printf.a lib/libft/libft.a -o test
./test
