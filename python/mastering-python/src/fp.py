# In The Name Of God
# ========================================
# [] File Name : fp.py
#
# [] Creation Date : 31-08-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================


def Y(f):
    return lambda *args: f(Y(f))(*args)


def factorial(combinator):
    def _factorial(n):
        if n:
            return n * combinator(n - 1)
        else:
            return 1
    return _factorial

print(Y(factorial)(5))
