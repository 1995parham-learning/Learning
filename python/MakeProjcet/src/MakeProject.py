#!/usr/bin/python3
# In The Name Of God
# ========================================
# [] File Name : MakeProject
#
# [] Creation Date : 19-04-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
__author__ = 'Parham Alvani'

import argparse
import os

parser = argparse.ArgumentParser(description="simple script to create simple C & assembly project structure")
parser.add_argument('projects', metavar='P', type=str, nargs='+',
                    help='Project names')
parser.add_argument('--fastc', default=False, action='store_true', help='Fast C project')
parser.add_argument('--fasts', default=False, action='store_true', help='Fast assembly project')

args = parser.parse_args()

for project in args.projects:
    print("start creating %s" % project)
    if os.path.exists(project):
        print("%s folder exists" % project)
        continue
    # build project directory
    os.mkdir(project)

    # create .gitignore file
    gitignore = open(os.path.join(project, '.gitignore'), "w")
    gitignore.write("%s" % project)
    gitignore.close()
    del gitignore

    # create README.md file
    readme = open(os.path.join(project, 'README.md'), "w")
    readme.write("%s\n===========" % project)
    readme.close()
    del readme

    # Fast C project
    if args.fastc:
        os.spawnvp(os.P_WAIT, 'vim', ['vim', '-c', 'wq', '%s' % os.path.join(project, '%s.c' % project)])
        os.spawnvp(os.P_WAIT, 'vim',
                   ['vim', '-E', '-c', '%%s/P=/P=%s' % project, '%s' % os.path.join(project, 'Makefile'), '-c', 'wq'])
        os.spawnvp(os.P_WAIT, 'vim',
                   ['vim', '-E', '-c', '%%s/OBJ=/OBJ=%s.o' % project, '%s' % os.path.join(project, 'Makefile'), '-c',
                    'wq'])

    # Fast assembly project
    if args.fasts:
        os.spawnvp(os.P_WAIT, 'vim', ['vim', '-c', 'wq', '%s' % os.path.join(project, '%s.c' % project)])
        os.spawnvp(os.P_WAIT, 'vim',
                   ['vim', '-E', '-c', '%%s/P=/P=%s' % project, '%s' % os.path.join(project, 'Makefile'), '-c', 'wq'])
        os.spawnvp(os.P_WAIT, 'vim',
                   ['vim', '-E', '-c', '%%s/OBJ=/OBJ=%s.o' % project, '%s/' % os.path.join(project, 'Makefile'), '-c',
                    'wq'])
