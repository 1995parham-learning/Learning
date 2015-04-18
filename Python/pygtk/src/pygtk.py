# In The Name Of God
# ========================================
# [] File Name : pygtk
#
# [] Creation Date : 18-04-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
__author__ = 'Parham Alvani'

from gi.repository import Gtk


class Base:
    def __init__(self):
        self.window = Gtk.Window()
        self.window.show()

    @staticmethod
    def main():
        Gtk.main()


print(__name__)
if __name__ == "__main__":
    base = Base()
    base.main()