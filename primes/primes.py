
# cache primes from database


# iterative method
def is_prime(n):
    #return a bolean if it's prime or not 
    # first step if it's even and not two it's not prime
    if(n == 2 or n == 5 or n == 3):
        return True
    elif (n % 2 == 0 or n % 5 == 0 or n % 3 == 0):
        return False
    # we want to iterate where i < n**.5 
    else: 
        i = 5
        while i <= n**.5:
            if n % i == 0:
                return False
            i = i + 2
        else:
            return True

