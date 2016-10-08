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
from bluetooth.ble import GATTRequester
import sys

service = DiscoveryService()
devices = service.discover(2)

class Reader():
    def __init__(self, address):
        self.requester = GATTRequester(address, False)
        self.connect()
        self.request_data()
        self.turn()

    def connect(self):
        print("Connecting...", end=' ')
        sys.stdout.flush()

        self.requester.connect(True)
        print("OK!")

    def request_data(self):
        data = self.requester.read_by_handle(0x03)
        print("Device name: " + str(data))

        candle = self.requester.read_by_handle(0x23)
        print("Candle: " + str(candle))


    def turn(self):
        self.requester.write_by_handle(0x0016, str(bytearray([0, 0, 0, 0])))


for address, name in devices.items():
    print("name: {}, address: {}".format(name, address))
    Reader(address)
    print("Done.")
