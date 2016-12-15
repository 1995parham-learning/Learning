# In The Name Of God
# ========================================
# [] File Name : pdb-hello.py
#
# [] Creation Date : 15-12-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
import pdb


def spam():
    print("Hello I am here")
    print("Hello I am there ?")
    print("Bye ! I always here !")

if __name__ == "__main__":
    pdb.set_trace()
    spam()
