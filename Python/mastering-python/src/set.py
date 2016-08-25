# In The Name Of God
# ========================================
# [] File Name : set.py
#
# [] Creation Date : 25-08-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================


def print_set(expression, set_):
    'Print set as a string sorted by letters'
    print(expression, ''.join(sorted(set_)))

spam = set('spam')
print_set('spam:', spam)

eggs = set('eggs')
print_set('eggs:', eggs)

parham = {'p', 'a', 'r', 'h', 'a', 'm'}
print_set('parham:', parham)
