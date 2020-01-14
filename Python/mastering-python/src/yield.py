# In The Name of God
# =======================================
# [] File Name : yield.py
#
# [] Creation Date : 14-01-2020
#
# [] Created By : Parham Alvani <parham.alvani@gmail.com>
# =======================================

def fibonacci():
    print('initiation')
    n = 0
    a, b = 0, 1
    while True:
        print(f'{n}')
        yield b
        a, b = b, a + b
        n += 1
fibo = fibonacci()
print(f'n: 0')
next(fibo)
print(f'n: 1')
next(fibo)

def psychologist():
    print('Please tell me your problem')
    while True:
        answer = (yield)
        if answer is not None:
            if answer.endswith('?'):
                print("Don't ask yourself too much questions")
            elif 'good' in answer:
                print("Ahh that's good, go on")
            elif 'bad' in answer:
                print("Don't be so negative")

free = psychologist()
next(free) # can't send non-None value to a just-started generator
free.send('I feel bad')
free.send("Why I shouldn't?")
free.send("ok then I should find what is good for me")
