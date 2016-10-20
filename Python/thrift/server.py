# In The Name Of God
# ========================================
# [] File Name : server.py
#
# [] Creation Date : 11-10-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
import thriftpy
from thriftpy.rpc import make_server

watraft_thrift = thriftpy.load("WatRaft.thrift", module_name="watraft_thrift")


class Dispatcher:
    def get(self, key: str):
        return "Amusse you get the value of %s" % key

    def put(self, key: str, val: str):
        return "Ammuse %s is put into %s" % (value, key)

    def append_entries(self, term: int, leader_id: int,
                       prev_log_index: int, prev_log_temr: int,
                       entries: list, leader_commit_index: int):
        return "You take this shit seriously"

server = make_server(watraft_thrift.WatRaft, Dispatcher(), '127.0.0.1', 6000)
server.serve()
