# import math 
# (Use sqrt func for optimize on sieve main forloop, O(n log log n))
#
#
# NO ERROR HANDLING HAS BEEN IMPLEMENTED
# WILL ONLY RUN IF POSITIVE INT >0 IS INPUT





##
# Based on ALGO FROM https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
#
# Input: any number in Z > 1
# Output: list of primes p, such that 2 <= p <= n
##
def sieve(n: int) -> list:
    '''
    - domain is a bool list from 2 <= i <= n
    - domain is init to all TRUE
    '''
    domain = [True for i in range(n+1)]

    '''
    - Loop from 2 <= i < (n+1) or for Optimized use sqrt(n)
    - If curr index is True --> set all i^2, i^2+i,i^2+2i... to False
    - Once range exceeded, all False values == Prime
    - Commented out code will show the actual algo running in the terminal
      only really good for seeing how it works, Uses small number or it gets
      to busy.
    '''
    round = 0
    for i in range(2, n+1):
        # print(str(round)+": --> ",end=" ")
        # round += 1
        # for k in range(2,n+1):
        #     if domain[k]:
        #         print("T", end=",")
        #     else:
        #         print("F", end=",")
        # print("\n")        
        if (domain[i] == True):
            for j in range(pow(i,2), n+1, i):
                domain[j] = False
    # print("\n")
    primes = []
    for isPrime in range(2, n+1):
        if domain[isPrime]:
            primes.append(isPrime)
    return primes


# Format output
def printPrimes(tmp: list, length: int):
    LastPrime = tmp[-1]
    for i in tmp:
        if (i == LastPrime):
            print(i)
            continue
        print(i, end=",")
    print(str(len(tmp)) + " Primes from 2 through " + str(length))



def main():
    # Grab UI
    searchRange = int(input("ENTER AN INTEGER: "))

    # Main method, actually doing all the dirty work
    primesList = sieve(searchRange)
    
    # This will just print the primes out from 2-n
    # printPrimes(primesList,searchRange)
    # Hardcode exit messege if printPrimes() isnt enabled
    print(str(len(primesList)) + " Primes from 2 through " + str(searchRange))
main()