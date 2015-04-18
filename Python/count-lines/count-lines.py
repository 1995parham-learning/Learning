# In The Name Of God
# ========================================
# [] File Name : count-lines.py
#
# [] Creation Date : 21-01-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
import logging
import sys
import os
import time


def count_lines(filename):
    """
    Count the number of lines in file. If the file can't be
    opened, it should be treated the same as if it was empty
    """

    ifile = None
    try:
        ifile = open(filename, 'r')
        lines = ifile.readlines()
    except TypeError as exp:
        logging.error(exp)
        return 0
    except IOError as exp:
        logging.error(exp)
        return 0
    except UnicodeDecodeError as exp:
        logging.error(exp)
        return 0
    else:
        # print(lines)
        return len(lines)
    finally:
        if ifile:
            ifile.close()


i = 1
while i < len(sys.argv):
    print(os.path.abspath(sys.argv[i]))
    print(time.ctime(os.path.getctime(sys.argv[i])))
    print(count_lines(sys.argv[i]))
    i += 1
