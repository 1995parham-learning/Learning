# In The Name Of God
# ========================================
# [] File Name : ble-sample.py
#
# [] Creation Date : 07-10-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

# bluetooth low energy scan
from bluetooth.ble import DiscoveryService

service = DiscoveryService()
devices = service.discover(2)

for address, name in devices.items():
        print("name: {}, address: {}".format(name, address))
