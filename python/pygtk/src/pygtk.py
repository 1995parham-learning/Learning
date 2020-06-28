# In The Name Of God
# ========================================
# [] File Name : pygtk.py
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
        self.window.set_title("Parham Alvani")
        self.button = Gtk.Button(label="Button-1")
        self.window.add(self.button)
        self.button.connect("clicked", Base.hello, None)
        self.window.show_all()
        self.window.connect("destroy", Base.exit, None)

    @staticmethod
    def hello(widget, arg):
        """
        :param widget: the widget to operate on
        :param arg: user-supplied data
        :type widget: Gtk.Widget
        :type arg: object
        :return:
        """
        print(widget.get_name())
        print("hello")

    @staticmethod
    def exit(widget, arg):
        """
        :param widget: the widget to operate on
        :param arg: user-supplied data
        :type widget: Gtk.Widget
        :type arg: object
        :return:
        """
        Gtk.main_quit()

    @staticmethod
    def main():
        Gtk.main()


print(__name__)
if __name__ == "__main__":
    base = Base()
    base.main()