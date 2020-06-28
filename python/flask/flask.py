# In The Name Of God
# ========================================
# [] File Name : flask.py
#
# [] Creation Date : 30-08-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
from flask import Flask
app = Flask(__name__)


@app.route("/")
def hello():
    return "Hello World!"

if __name__ == "__main__":
    app.run()
