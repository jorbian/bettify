#!/bin/sh

[ $(ps -o stat= -p $PPID) = "Ss" ]

IS_INTERACTIVE=$?

HEADER_DEFAULT_PATH=./new_header.h
HEADER_TEMPLATE="#ifndef NAME\n#define NAME\n\n/* CODE GOES HERE */\n\n#endif /* NAME */\n"

NEW_HEADER_PATH=$([ -z $1 ] && printf '%s' $HEADER_DEFAULT_PATH || printf '%s' $1)
NEW_HEADER_NAME="$(printf "$NEW_HEADER_PATH" | grep -o -P '(?<=\/)[^\/]+(?=\..*$)' | tr 'a-z' 'A-Z')"
NEW_HEADER_CONTENT="$(printf "$HEADER_TEMPLATE" | sed "s/NAME/$NEW_HEADER_NAME/")"

if test -f $NEW_HEADER_PATH; then
    ERROR="$(printf "ALREADY EXISTS")"
fi

if [ "${NEW_HEADER_PATH##*.}" != "h" ]; then 
    ERROR="$(printf "HAS WRONG EXTENSION")"
fi

if [ -n "$ERROR" ]; then
    if [ $IS_INTERACTIVE -eq 0 ]; then
        printf "%s: '%s' %s\n" "$0" "$NEW_HEADER_PATH" "$ERROR"
    fi
    exit 1
fi

printf "$NEW_HEADER_CONTENT\n" > $NEW_HEADER_PATH
