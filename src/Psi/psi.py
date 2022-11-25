#TODO
# Hand wrtie gcd to optimize large calls
import matplotlib.pyplot as plt
import numpy as np
import math

def totient(m):
    totSet = []
    for i in range(m):
        if(math.gcd(i,m)==1):
            totSet.append(i)
    return len(totSet)

def graphPsi(x, y):
    plt.scatter(x,y,s=0.1, c='r')
    plt.margins(x=0)
    plt.title("Euler's Phi Function")
    plt.ylabel("Phi(m)")

    # Plot verify
    # print(np.interp(849, y,x))
    plt.show()
    



def main():
    bound = int(input("Enter an upper bound: "))
    PsiPool = []
    axis = []
    for i in range(1, bound+1):
        Psi = totient(i)
        PsiPool.append(Psi)
        axis.append(i)
    graphPsi(axis, PsiPool)
main()