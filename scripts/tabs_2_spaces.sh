#!/bin/sh

ERROR_MESSAGE="$(printf "USAGE: %s FILENAME (EXT)?" $0)"

if [ $# -lt 1 ]; then
    printf "$ERROR_MESSAGE\n"
    exit 1
fi

INPUT_FILE=$1

sed -i "s/\t/    /" $INPUT_FILE
