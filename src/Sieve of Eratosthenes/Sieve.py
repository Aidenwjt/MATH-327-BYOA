import math
# import tkinter as tk

# window = tk.Tk()
# to rename the title of the window
# window.title("Sieve")
# pack is used to show the object in the window
# window.mainloop()

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
    round = 0
    for i in range(2, n+1):
        print(str(round)+": --> ",end=" ")
        round += 1
        for k in range(2,n+1):
            if domain[k]:
                print("T", end=",")
            else:
                print("F", end=",")

        print("\n")        
        if (domain[i] == True):
            for j in range(pow(i,2), n+1, i):
                domain[j] = False
 
    print("\n")

    primes = []
    for isPrime in range(2, n+1):
        if domain[isPrime]:
            primes.append(isPrime)
    return primes


'''
Test to see how many primes are in a range
cross check with google to see if correct...
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
    searchRange = 10
    primesList = sieve(searchRange)
    # printPrimes(primesList)
    primeTest(primesList,searchRange)
main()