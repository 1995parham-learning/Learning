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

# updates the copyright information for input files

import sys
import time
import os

c_header = """/*
 * In The Name Of God
 * ========================================
 * [] File Name : ${filename}
 *
 * [] Creation Date : ${date}
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
"""

py_header = """# In The Name Of God
# ========================================
# [] File Name : ${filename}
#
# [] Creation Date : ${date}
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
__author__ = 'Parham Alvani'
"""


def update_source_c(srcfile):
    """

    :param srcfile: name of target C source file
    :return: nothing
    """
    print("Updating %s\n" % srcfile)
    file_header = c_header.replace("${filename}", srcfile)
    file_date_header = file_header.replace("${date}", time.strftime("%d-%m-%Y"))
    file_data = open(srcfile, "r").read()
    file = open(srcfile, "w")
    file.write(file_date_header + file_data)
    return


def update_source_py(srcfile):
    """

    :param srcfile: name of target python source file
    :return: nothing
    """
    print("Updating %s\n" % srcfile)
    file_header = py_header.replace("${filename}", srcfile)
    file_date_header = file_header.replace("${date}", time.strftime("%d-%m-%Y"))
    file_data = open(srcfile, "r").read()
    file = open(srcfile, "w")
    file.write(file_date_header + file_data)
    return


def update_source(srcfile):
    """

    :param srcfile: name of target source file
    :return: nothing
    """
    options = {
        '.c': update_source_c,
        '.h': update_source_c
    }
    if os.path.splitext(srcfile)[-1] in options:
        options[os.path.splitext(srcfile)[-1]](srcfile)


while len(sys.argv) > 1:
    filename = sys.argv.pop()
    update_source(filename)
exit()