#!/usr/bin/python3

import re
import math

def remove_c99_comments(lines: str) -> str:
    """REMOVES C99 STYLE COMMENTS FROM A '.c' OR '.h' FILE"""
    return (
        re.sub(
            re.compile('\/\/.*$', re.MULTILINE), "", lines
        )
    )


def trim_trailing_whitespace(lines: str) -> str:
    """REMOVES TRAILING WHITESPACE FROM EACH LINE OF CODE"""
    return (
        "\n".join(
            x.rstrip() for x in
                lines.split("\n")
        )
    )


def convert_indentation_to_tabs(lines: str) -> str:
    """CONVERTS INDENTATION FROM FOUR SPACE TO TABS"""
    leading_spaces = tuple(
        len(a) - len(a.lstrip(' ')) for a in lines.split("\n")
            if (a.strip() != "")
    )
    if (not any(leading_spaces)):
        return (lines)

    tab_size = math.gcd(
        *tuple(
            set(x for x in leading_spaces if x)
        )
    )
    return (
        lines.replace((' ' * tab_size), "\t")
    )
    

def fix_return_statements(lines: str) -> str:
    """MAKES SURE THERE ARE PARENTHESES AROUND RETURN VALS OF FUNCTION"""
    find_bad_return = re.compile(
        "^\s+return((\s[^()\n]+)|(\(.*\)));$", re.MULTILINE
    )
    for match_obj in (re.finditer(find_bad_return, lines)):    

        ret_val = ((match_obj.groups())[0].strip())

        if (ret_val[0], ret_val[-1]) != ('(', ')'):
            ret_val = "({})".format(ret_val)

        lines = lines.replace(
            match_obj.group().strip(),
            "return {};".format(ret_val)
        )
    return (lines)


def fix_operator_spacing(lines: str) -> str:
    return (lines)


def fix_function_headers(lines: str) -> str:
    """changes 'void do_stuff()' to 'void do_stuff(void)'"""
    find_function_header = re.compile(
        "^[a-zA-Z_]\w*\s+[a-zA-Z_*]\w*\s*(\([^;]*\))",
        flags=re.M
    )
    header_matches = re.finditer(
        find_function_header, lines
    )
    for match_obj in header_matches:
        params = (match_obj.groups())[0]
        if (len(params) > 2):
            continue

        new_header = (match_obj.group()).replace(
            (match_obj.groups())[0], "(void)"
        )
        lines = lines.replace(match_obj.group(), new_header)

    return (lines)

