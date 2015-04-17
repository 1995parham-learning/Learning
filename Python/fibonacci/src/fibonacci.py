# In The Name Of God
# ========================================
# [] File Name : fibonacci
#
# [] Creation Date : 17-04-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
__author__ = 'Parham Alvani'


class Fibonacci:
    """
    simple class for making fibonacci number with divide & conquer and
     dynamic programming methods.
    """

    def __init__(self):
        """
        build fibonacci object for you
        :return: nothing
        """
        self.list = list([0, 1])

    def get_fibonacci(self, index):
        """
        :param index: fibonacci sequence number
        :return: fibonacci at sequence number
        :raise: TypeError if index not a integer
        """
        if not isinstance(index, int):
            raise TypeError
        if self.list.__len__() - 1 >= index:
            return self.list[index]
        else:
            while self.list.__len__() - 1 < index:
                self.list.append(self.list[-1] + self.list[-2])
            return self.list[index]


fibonacci = Fibonacci()
var = input("Please enter fibonacci sequence number ")
var = int(var)
print(fibonacci.get_fibonacci(var))

# Test string operations
s = str("Hello world of %s" % "python")
print(s)
print(fibonacci.list)