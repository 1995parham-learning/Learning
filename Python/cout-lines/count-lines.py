import logging
import sys

def count_lines(filename):
    """
    Count the number of lines in file. If the file can't be
    opened, it should be treated the same as if it was empty
    """
    file = None
    try:
        file = open(filename, 'r')
        lines = file.readlines()
    except TypeError as e:
        logging.error(e)
        return 0
    except EnvironmentError as e:
        logging.error(e.args[1])
        return 0
    except UnicodeDecodeError as e:
        logging.error(e)
        return 0
    else:
        print(lines)
        return len(lines)
    finally:
        if file:
            file.close()

i = 1
while i < len(sys.argv):
    print sys.argv[i]
    count_lines(sys.argv[i])
    i = i + 1
