# In The Name of God
# =======================================
# [] File Name : yield.py
#
# [] Creation Date : 14-01-2020
#
# [] Created By : Parham Alvani <parham.alvani@gmail.com>
# =======================================

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
