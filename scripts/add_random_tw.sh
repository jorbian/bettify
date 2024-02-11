#!/bin/sh

FILE=binary_tree_print.c


SPACES="$(printf ' %.0s' $(seq 1 $(shuf -i 2-8 -n 1)))"

sed -i "s/$/$SPACES/" $FILE