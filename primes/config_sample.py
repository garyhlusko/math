import psycopg2 

config = {
    "host":"host",
    "user": "user",
    "password":"hunter2"
}

conn = psycopg2.connect(dbname = "math", user = config["user"], host=config["host"], password = config["password"])
cur = conn.cursor()
