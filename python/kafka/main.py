"""
driver location consumer from kafka.
"""

import json

from confluent_kafka import Consumer
from rich import pretty
from rich.color import Color
from rich.console import Console
from rich.style import Style

if __name__ == "__main__":
    console = Console(color_system="truecolor")
    pretty.install()

    c = Consumer(
        {
            "bootstrap.servers": "172.21.88.8:9094",
            "group.id": "test-dls",
            "auto.offset.reset": "latest",
        }
    )

    c.subscribe(["dls-elahe"])

    try:
        while True:
            msg = c.poll(1.0)

            if msg is None:
                continue
            if msg.error():
                print(f"Consumer error: {msg.error()}")
                continue

            location = json.loads(msg.value().decode("utf-8"))
            console.print(
                f"Received message with id equals to {msg.key()}:",
            )
            pretty.pprint(location)
    finally:
        console.print("Have nice day", style="bold red", justify="center")
        c.close()
