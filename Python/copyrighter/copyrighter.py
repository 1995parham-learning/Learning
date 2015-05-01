#!/usr/bin/python3
# In The Name Of God
# ========================================
# [] File Name : copyrighter
#
# [] Creation Date : 02-05-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
__author__ = 'Parham Alvani'

# updates the copyright information for all .cs files
# usage: call recursive_traversal, with the following parameters
# parent directory, old copyright text content, new copyright text content

import sys
import time

header = """/*
 * In The Name Of God
 * ========================================
 * [] File Name : ${filename}
 *
 * [] Creation Date : ${data}
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
"""


def update_source(srcfile):
    """

    :param srcfile: name of target source file
    :return:
    """
    file_header = header.replace("${filename}", srcfile)
    file_date_header = file_header.replace("${data}", time.strftime("%d-%m-%Y"))
    file = open(srcfile, "r+")
    file.write(file_date_header)


while len(sys.argv) > 1:
    filename = sys.argv.pop()
    update_source(filename)
exit()