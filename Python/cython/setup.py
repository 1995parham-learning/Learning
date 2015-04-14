#!/usr/bin/python
# In The Name Of God
# ========================================
# [] File Name : setup.py
#
# [] Creation Date : 14-04-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
__author__ = 'Parham Alvani'

from distutils.core import setup, Extension

py_modules = ['hello']

eModule = Extension('hello',
                    sources=['hello.py.c'])

setup(name='hello',
      version='1.0',
      description='Hello ...',
      ext_modules=[eModule])
