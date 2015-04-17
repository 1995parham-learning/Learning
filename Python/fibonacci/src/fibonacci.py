# In The Name Of God
# ========================================
# [] File Name : fibonacci
#
# [] Creation Date : 17-04-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
__author__ = 'Parham Alvani'


def fibonacci(n):
    if not isinstance(n, int):
        return None
    if n == 0 or n == 1:
        return 1
    return fibonacci(n - 1) + fibonacci(n - 2)


var = input("Please enter fibonacci sequence number ")
var = int(var)
print(fibonacci(var))