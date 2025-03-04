#!/bin/bash
gcc *.c -fsanitize=address,undefined,leak -Wpedantic -O0
