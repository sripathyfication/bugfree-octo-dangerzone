#/usr/bin/python

'''

    n & (n - 1) will go ahead and reset the rightmost set bit. This turns out to be useful 
    in a few applications.


    such as:

    1. Checking if a number is power of 2. If a number is a power of 2, it will have only 1 bit
    set. So, we can check if n & (n-1) returns 0. If so, then the number is a power of 2.

    2. Find the rightmost set bit. As n & n-1 unsets the right most set bit, we can then xor with
    the number itself, and it will give us the right most set bit.

    3. Finding parity. A number is set to have odd partiy if it has an odd number of bits set.
    it has even parity if it has even number of bits set.


'''
def is_pow_2(n):
    print " Is " +str(n) + " pow of 2"
    n = n & (n -1)
    return True if not n else False

def rightmost_setbit(n):
    print "rightmost_setbit for " + str(n)
    x = n & (n-1)
    return x ^ n

#
# In this case, the number of times it enters the while determines the parity
# if parity is True at the end of the loop, then it is odd parity.
# If parity is False at the end of the loop, then it is even parity.    
# It enters the loop only the number of times as the number of set bits in the integer.
def parity(n):
    print "Find the parity of " +str(n)
    parity = False
    while (n):
        parity = ~parity
        n = n&(n-1)
    return parity

print is_pow_2(5)
print rightmost_setbit(5)
print parity(5)
print parity(6)
