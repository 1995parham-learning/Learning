# In The Name of God
# =======================================
# [] File Name : main.py
#
# [] Creation Date : 14-08-2020
#
# [] Created By : Parham Alvani <parham.alvani@gmail.com>
# =======================================
import sys
import datetime
import typing
import random

import pymongo


def data() -> typing.Any:
    lng, lat = random.choice(
        [(51.4133924, 35.7944779), (50.952981, 35.723737)]
    )

    return {
        "data": {
            "motion": str(random.randint(0, 1)),
            "humidity": str(random.randint(0, 100)),
            "temperature": str(random.randint(20, 40)),
            "light": str(random.randint(0, 1024)),
            "_location": {"type": "Point", "coordinate": [lng, lat]},
        },
        "timestamp": datetime.datetime.now(),
        "thingid": "0000000000000074",
        "rxinfo": None,
        "txinfo": None,
        "project": "5d08d39f5958ce34d42058d6",
        "protocol": "lan",
        "model": "aolab",
    }


def usage():
    print(
        "main.py <database-url e.g. mongodb://127.0.0.1:27017>"
        "<database-name> <collection-name> <count>"
    )
    sys.exit(-1)


if __name__ == "__main__":
    if len(sys.argv) != 5:
        usage()
    cli = pymongo.MongoClient(sys.argv[1])
    db = cli[sys.argv[2]]
    collection = db[sys.argv[3]]

    for _ in range(int(sys.argv[4])):
        collection.insert_one(data())
