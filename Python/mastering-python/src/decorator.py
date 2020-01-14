# In The Name of God
# =======================================
# [] File Name : decorator.py
#
# [] Creation Date : 14-01-2020
#
# [] Created By : Parham Alvani <parham.alvani@gmail.com>
# =======================================
from typing import Callable, Dict
import functools

def fibo(n: int) -> int:
    if n == 1:
        return 1
    if n == 2:
        return 1
    return fibo(n - 1) + fibo(n - 2)

# as function
def memorize(f: Callable[[int], int]) -> Callable[[int], int]:
    memory: Dict[int, int] = dict()
    @functools.wraps(f)
    def wrapper(arg: int) -> int:
        if arg not in memory:
            memory[arg] = f(arg)
        return memory[arg]
    return wrapper

# as class
class Memorize:
    def __init__(self, f: Callable[[int], int]):
        self.function = f
        self.memory: Dict[int, int] = dict()
        functools.update_wrapper(self, f)

    def __call__(self, arg: int) -> int:
        if arg not in self.memory:
            self.memory[arg] = self.function(arg)
        return self.memory[arg]

ff = memorize(fibo)
fc = Memorize(fibo)
print(f'{ff(10)} as function and {fc(10)} as class')
