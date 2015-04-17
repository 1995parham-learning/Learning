# In The Name Of God
# ========================================
# [] File Name : pygtk
#
# [] Creation Date : 18-04-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
__author__ = 'Parham Alvani'

import pygtk

pygtk.require('2.0')
import gtk


class Base:
    def __init__(self):
        self.window = gtk.Window(gtk.WINDOW_TOPLEVEL)
        self.window.show()

    @staticmethod
    def main():
        gtk.main()


print(__name__)
if __name__ == "__main__":
    base = Base()
    base.main()