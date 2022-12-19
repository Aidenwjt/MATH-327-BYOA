import matplotlib.pyplot as plt
#############################################
# - striaght forward implmentation of the 
#   Eulers Psi Function.
# NOTE:
#   NO ERROR HANDLING HAS BEEN IMPLEMENTED
#   WILL ONLY RUN IF POSITIVE INT IS INPUTED
#############################################

# Optimized code used from https://stackoverflow.com/questions/11175131/code-for-greatest-common-divisor-in-python
def gcd(index, m):
    while m != 0:
        (index, m) = (m, index % m)
    return index

# This function uses memoization as an attmept
# to save runtime since the totient func() is 
# a stack hog.
# Simple dict. stores past calculated totient value
# @memoize_totient is called a decorater, its used 
# to call the higher order func we use for memoization.
MAP = {} 
def memoize_totient(Curr):
    
    def helper(m):
        if m not in MAP:
            MAP[m] = Curr(m)
        return MAP[m]
    return helper
@memoize_totient
def totient(m):
    totSet = []
    for i in range(m):
        if(gcd(i,m)==1):
            totSet.append(i)
    return len(totSet)


# This function will graph our list of all totients 
# we have calculated against 1,...,n.
def graphPsi(x, y):
    plt.scatter(x,y,s=0.1, c='r')
    plt.margins(x=0)
    plt.title("MATH-327\n Euler's Phi Function")
    plt.ylabel("Phi(n)")
    plt.xlabel("n")
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