# In The Name Of God
# ========================================
# [] File Name : hello.py
#
# [] Creation Date : 12-04-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
__author__ = 'Parham Alvani'

print("Hello world of python")
print(1 + 1)
print(1.0 + 1)
parham = 1
print(parham)

a = ("Parham", "Navid", "Mohammad")
b = (a, "Bahador")
print(b)
print(a.count("Parham"))

a = ["Parham", "Navid", "Mohammad"]
b = [a, "Bahador"]
print(b)
b[0][0] = "Parham Alvani"
print(a)
a.sort()
print(a)

var = [10, 20, 30]
c = (var, 10)
print(c)
var = var.append(40)
print(c)

for name in a:
    print(name)
else:
    print("While finish correctly")


def retfunc(a):
    def f(b):
        print("%d %d" % (a, b))
    return f
retfunc(10)(20)
