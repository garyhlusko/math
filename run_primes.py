import primes 
import psycopg2
from config import cur,conn

def get_last_searched():
    cur.execute("Select last_searched from results where schema = 'primes'")
    rows = cur.fetchone()
    return int(rows[0])

def insert_prime(n):
    cur.execute("INSERT INTO primes (prime_number) VALUES ({})".format(n))
    conn.commit()

def update_last_searched(n):
    cur.execute("UPDATE results set last_searched = {} where schema = 'primes'".format(n))
    conn.commit()

def run():
    last_searched = get_last_searched()
    # make sure next searched is odd 
    i = last_searched
    if (i % 2 == 0):
        i = i + 1
    else:
        i = i + 2
    print("starting search")
    while 1:
        if (last_searched - i ) % 10000 == 0:
            update_last_searched(i)
        if primes.is_prime(i):
            print("Found prime: {}".format(i))
            insert_prime(i)
        i = i + 2

if __name__ == "__main__":
    run()
