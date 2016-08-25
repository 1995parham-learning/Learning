# In The Name Of God
# ========================================
# [] File Name : list.py
#
# [] Creation Date : 25-08-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
# List - a mutable list of items
l1 = [1, 2, 3]
print(l1)
l1.append(4)
print(l1)

primes = (1, 2, 3, 5, 7)
numbers = list(range(10))
not_primes = [number for number in numbers if number not in primes]
print(not_primes)
