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
    except EnvironmentError as exp:
        logging.error(exp.args[1])
        return 0
    except UnicodeDecodeError as exp:
        logging.error(exp)
        return 0
    else:
        print lines
        return len(lines)
    finally:
        if file:
            file.close()

i = 1
while i < len(sys.argv):
    print sys.argv[i]
    count_lines(sys.argv[i])
    i = i + 1
