from distutils.core import setup, Extension

py_modules = ['hello']

Emodule = Extension('hello',
        sources = ['hello.py.c'])

# Emodule = Extension('hello',
#               sources = ['hello.py.c']
#               libraries = ['hello']
#               library_dirs = ['.']
#
#

setup(name = 'hello',
        version = '1.0',
        description = 'Hello ...',
        ext_modules = [Emodule])
