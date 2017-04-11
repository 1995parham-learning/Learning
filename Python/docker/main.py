# In The Name Of God
# ========================================
# [] File Name : main.py
#
# [] Creation Date : 11-04-2017
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

import docker

client = docker.DockerClient(base_url='tcp://192.168.73.8:2375')

print(client.containers)
print(client.containers.list())
