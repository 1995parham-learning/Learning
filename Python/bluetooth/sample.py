# In The Name Of God
# ========================================
# [] File Name : sample.py
#
# [] Creation Date : 07-10-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================


# simple inquiry example
import bluetooth

nearby_devices = bluetooth.discover_devices(lookup_names=True)
print("found %d devices" % len(nearby_devices))

for addr, name in nearby_devices:
        print("  %s - %s" % (addr, name))
