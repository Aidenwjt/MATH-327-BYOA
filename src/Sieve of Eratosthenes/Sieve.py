import math
'''
Based on ALGO FROM https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

Input: any number in Z > 1
Output: list of primes p, such that 2 <= p <= n
'''
def sieve(n: int) -> list:
    '''
    - domain is a bool list from 2 <= i <= n
    - domain is init to all TRUE
    '''
    domain = [True for i in range(n+1)]

    '''
    - Loop from 2 <= i < sqrt(n)
    - If curr index is True --> set all i^2, i^2+i,i^2+2i... to False
    - Once range exceeded, all False values == Prime
    '''
    for i in range(2, math.ceil(math.sqrt(n))):
        if (domain[i] == True):
            for j in range(pow(i,2), n+1, i):
                domain[j] = False

    
    primes = []
    for isPrime in range(2, n+1):
        if domain[isPrime]:
            primes.append(isPrime)
    return primes


'''
Test to see how many primes are in a range
cross check with gogole to see if correct...
Format output as well
'''
def primeTest(tmpList: list, length: int):
    print(str(len(tmpList)) + " Primes from 2 through " + str(length))


'''
Format output
'''
def printPrimes(tmp: list):
    LastPrime = tmp[-1]
    for i in tmp:
        if (i == LastPrime):
            print(i)
            continue
        print(i, end=",")


def main():
    searchRange = 10000
    primesList = sieve(searchRange)
    primeTest(primesList,searchRange)
main()