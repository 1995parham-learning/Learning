# Learning Codes
## Who Am I ?
I am simple lonely person who spent his life on code and ...
and this is what I have after many years of life ...

## Introduction
My personal learning code from C, Assembly, Python, ... collected
here. some of these code collected from
[my stackoverflow](http://stackoverflow.com/users/4242097/parham-alvani)
answers.
You can use these example as tutorial.

## Contribution
If you think you have such programming example you can send me [email](mailto:parham.alvani@gmail.com)
and I add them into this repository.

## Table of Code ?!
### C
Makefile is a good thing ! have this for have fun:
```Makefile
all: calc_lcm_gcd

calc_lcm_gcd: main.o gcd.o lcm.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)

%.o: %.c functions.h
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm main.o gcd.o lcm.o calc_lcm_gcd
```
check [here](http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/) for having even more fun !

#### [Threads](C/Threads)
Let's learn to use new feature in C11, C11 threads.
Please see [here](http://en.cppreference.com/w/c/thread) as a reference for C11 threads.

### Python
It's better to use `pyvenv` with your python code:
```sh
# Setup
pyvenv .
# Activate
. ./bin/activate
# Deactive
deactive
```
#### [Bluetooth](Python/bluetooth)
simple program for using bluetooth in python.
In order to use this code on linux you need to install `libbluetooth-dev`
package.
```sh
sudo apt-get install libbluetooth-dev
```
If you want to use BLE version of this library you need following dependencies:
```sh
sudo apt-get install libglib2.0-dev pkg-config libboost-dev libboost-python-dev libboost-thread-dev
git clone https://github.com/1995parham/pygattlib.git && cd pygattlib
sudo python3 setup.py install
```
If you want to access your low power bluetooth devices directly from linux shell
you can use HCI tools like this:
```sh
# First check HCI device is up and running
sudo hciconfig
# If you HCI device is down :(
sudo hciconfig hci0 up
# Let's start a scan for LE (Bluetooth LE or Bluetooth smart) devices
sudo hcitool lescan
```
#### [Flask](Python/flask)
It's a simple flask application that I had written in the day that 18.20 left me.

#### [Mastering Python](Python/mastering-python)
Sample codes of Mastering Python book that is written by Rick van Hattem.

#### [Renamer](Python/renamer)
Simple project for renaming your downloaded TV series or Wallpapers to better naming structure.
It's far from complete project that can do these things in professional manner.

#### [Thrift](Python/thrift)
Let's learn this new animal in Python, first of all we use pure python edition of Thrift form
[here](https://github.com/eleme/thriftpy). This example was written for having more fun in our
trash life ...

#### [eMQTT](Python/emqtt)
First up and run your [eMQTT](http://emqtt.io/) broker.
```sh
unzip emqttd-macosx-v2.0-beta.2-20160910.zip && cd emqttd

# Start emqttd
./bin/emqttd start

# Check Status
./bin/emqttd_ctl status

# Stop emqttd
./bin/emqttd stop
```
Your dashboard available at `:18083` with **admin:public**.

#### [Python-YACC](Python/python-yacc)
Sample code for using [Python Lex-Yacc (PLY)](http://www.dabeaz.com/ply/ply.html)
in your Lonely nights.

### Shell
#### [chert-2-1](Shell/chert-2/chert-2-1.sh)
Print the names and determine the number of files in /bin directory whose
first letter is ‘c’.

#### [chert-2-2](Shell/chert-2/chert-2-2.sh)
Print the names of the first 7 files of /etc directory.

#### [chert-2-3](Shell/chert-2/chert-2-3.sh)
Print the names and determine the number of files of /etc directory that
contain ‘z’.

#### [chert-2-4](Shell/chert-2/chert-2-4.sh)
Print 10 commands of /bin sorting by the last access time.

#### [chert-2-5](Shell/chert-2/chert-2-5.sh)
Create a file containing the names of the first 7 files and the last 6 files of
/etc directory, in alphabet order.

#### [chert-2-6](Shell/chert-2/chert-2-6.sh)
Print the name of 8 files in /usr/sbin/ sorting by the last modification time.

#### [chert-2-7](Shell/chert-2/chert-2-7.sh)
Create a file in /home/directory1, write "hello world !" in it and copy it to a
new /home/directory2. Finally, remove it from directory1.

#### [power](Shell/power.sh)
Do you want integer power function in bash.
```sh
power.sh 10 2
```

### Go
#### [Once](Go/once)
Go uses zero initiation but sometimes you want some initiation and you want it lazy ...
#### [Thrift](Go/thrift)
Let's learn this new animal in Go, first install the compiler
```sh
sudo apt-get install thrift-compiler
```
then create your thrift file to describe your protocol
