
this is a folder to calculate primes. Right now it just uses a basic interative method.
I was annoyed at how slow python was running so I wrote another program in C.

# Iterative method
1. To speed up the iterative method, I don't check for even numbers because other than 2, none are prime
2. I only iterate up to the square root of a number, because if there isn't factored before or equal to the square root then it's prime.       
    Otherwise both factors would be greater than the square root of n which would mean that n > n and leads to a contradiction.
3. I personally get annoyed at multiples of five. (There's no reason) so I first check for factors of 3 and 5 and start the iteration at 7.

## Running the iterative method
## python 
Use the sample config file in the python package to set up your database connection (assuming postgres). 
After that change it to config.py
run `python3 primes.py` 

## C
## I ran this on ubuntu
You'll have to configure the PGcon with your connection.
afterwards compile with  gcc -o prime primes.c -L/usr/local/pgsql/lib -lpq -lm
you can then run with `./prime`

## Things that can be improved
### Adding a last search on exit 
if you kill the script and start over, it'll start with the largest prime and not the last search. 
So you'll rescan numbers you already did. IIRC, mathematicians have proven that given any number on the number line there's a prime in 10,000, so not a large cost.
