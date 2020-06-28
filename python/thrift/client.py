# In The Name Of God
# ========================================
# [] File Name : client.py
#
# [] Creation Date : 11-10-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
import thriftpy
from thriftpy.rpc import make_client

watraft_thrift = thriftpy.load("WatRaft.thrift", module_name="watraft_thrift")

client = make_client(watraft_thrift.WatRaft, '127.0.0.1', 6000)
print(client.get('parham'))

