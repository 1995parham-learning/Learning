# In The Name of God
# =======================================
# [] File Name : main.py
#
# [] Creation Date : 15-05-2020
#
# [] Created By : Parham Alvani <parham.alvani@gmail.com>
# =======================================


class Alg:
    def __get__(self, obj, objtype):
        return self

    def __call__(self):
        pass


class Alg1(Alg):
    def __call__(self):
        print("Alg-1")


class Alg2(Alg):
    def __call__(self):
        print("Alg-2")


class Core:
    def __init__(self, alg: Alg):
        self.alg = alg


c1 = Core(Alg1())
c2 = Core(Alg2())

c1.alg()
c2.alg()
