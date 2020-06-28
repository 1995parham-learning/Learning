# In The Name of God
# =======================================
# [] File Name : main.py
#
# [] Creation Date : 15-05-2020
#
# [] Created By : Parham Alvani <parham.alvani@gmail.com>
# =======================================
import abc


class Alg(abc.ABC):
    def __init__(self):
        pass

    def __get__(self, obj, objtype):
        self.core = obj
        return self

    def __call__(self):
        return self.run()

    @abc.abstractmethod
    def run(self):
        pass


class Alg1(Alg):
    def run(self):
        return f"Alg-1 from {self.core.name}"


class Alg2(Alg):
    def run(self):
        return f"Alg-2 from {self.core.name}"


class Core:
    alg: Alg = Alg1()

    def __init__(self, name: str = "default"):
        self.name = name


c1 = Core("elahe")
c2 = Core("raha")

assert c1.alg() == "Alg-1 from elahe"
assert c2.alg() == "Alg-1 from raha"

Core.alg = Alg2()

assert c1.alg() == "Alg-2 from elahe"
assert c2.alg() == "Alg-2 from raha"
