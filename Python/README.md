# Python
It's better to use `pyvenv` with your python code:
```sh
# Setup
pyvenv .
# Activate
. ./bin/activate
# Deactive
deactive
```
## [Bluetooth](bluetooth)
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

# [Flask](flask)
It's a simple flask application that I had written in the day that 18.20 left me.

## [Mastering Python](mastering-python)
Sample codes of Mastering Python book that is written by Rick van Hattem.

## [Renamer](renamer)
Simple project for renaming your downloaded TV series or Wallpapers to better naming structure.
It's far from complete project that can do these things in professional manner.

## [Thrift](thrift)
Let's learn this new animal in Python, first of all we use pure python edition of Thrift form
[here](https://github.com/eleme/thriftpy). This example was written for having more fun in our
trash life ...

## [eMQTT](emqtt)
First up and run your [eMQTT](http://emqtt.io/) broker, then use this example to have fun.
