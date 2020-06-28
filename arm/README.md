# Installing ST-Link v2

```sh
git clone https://github.com/texane/stlink stlink.git
cd stlink
make
#install binaries:
sudo cp build/Release/st-* /usr/local/bin
#install udev rules
sudo cp etc/udev/rules.d/49-stlinkv* /etc/udev/rules.d/
#and restart udev
sudo service udev restart
```
