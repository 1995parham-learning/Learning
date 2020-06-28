# In The Name of God
# =======================================
# [] File Name : main.py
#
# [] Creation Date : 21-05-2020
#
# [] Created By : Parham Alvani <parham.alvani@gmail.com>
# =======================================


class ProviderMeta(type):
    def __new__(mcs, name, bases, namespace):
        print(name)

        return super().__new__(mcs, name, bases, namespace)


class Provider(metaclass=ProviderMeta):
    pass


class Hello(Provider):
    pass


class Bye(Provider):
    pass
