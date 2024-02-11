#!/bin/sh

ERROR_MESSAGE="$(printf "USAGE: %s FILENAME" $0)"

if [ $# -lt 1 ]; then
    printf "$ERROR_MESSAGE\n"
    exit 1
fi

FILE=$1

SPACES="$(printf ' %.0s' $(seq 1 $(shuf -i 2-8 -n 1)))"

sed -i "s/$/$SPACES/" $FILE