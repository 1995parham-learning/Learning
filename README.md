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
If you want to access your bluetooth devices directly from linux shell
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
