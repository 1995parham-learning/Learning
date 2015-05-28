import sys

sys.path.insert(0, 'build/lib.linux-x86_64-2.7/')

from hello import *

print("%ld" % hello_c('Parham Alvani'))
