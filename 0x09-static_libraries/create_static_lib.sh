#!/bin/bash
gcc -Wall -pedamtic -Werror -Wextra -c *.c
ar -rc liball.a *.o
ranlib liball.a
