#!/usr/bin/python3
# In The Name Of God
# ========================================
# [] File Name : renamer.py
#
# [] Creation Date : 18-04-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
__author__ = 'Parham Alvani'

import os
import shutil
import cmd

try:
    import termcolor
except ImportError:
    termcolor = None


class Rename(cmd.Cmd):
    def __init__(self):
        super(Rename, self).__init__()
        self.path = '.'
        self.mode = 'pictures'
        self.intro = "{0:*^80}\n{1:=^80}\n".format("Welcome", "Renamer program for organizing pictures and tv series")
        self.prompt = "Renamer> [{0}] ".format(self.mode)
        if termcolor:
            self.prompt = termcolor.colored(self.prompt, color="red")

    def do_rename(self, line: str):
        print("{0:=^80}".format("Renaming start"))
        if self.mode == 'pictures':
            print("Mode: {0:<80}".format(self.mode))
            print("Path: {0:<80}".format(self.path))
            index = 1
            for file in sorted(os.listdir(self.path)):
                extension = os.path.splitext(file)[1]
                if extension.lower() == ".jpg":
                    name = "{0}.jpg".format(index)
                    index += 1
                    shutil.move(file, name)
                    print("mv {0} {1}".format(file, name))
        print("{0:=^80}".format("Renaming end"))

    def do_shell(self, line: str):
        os.system(line)

    def do_quit(self, line: str):
        return True

    def do_mode(self, line: str):
        if line.lower() == 'pictures':
            self.mode = 'pictures'
        elif line.lower() == 'tv-series':
            self.mode = 'tv-series'
        else:
            print("*** Unknown mode: {0}".format(line))

    do_EOF = do_quit


cli = Rename()
cli.cmdloop()
