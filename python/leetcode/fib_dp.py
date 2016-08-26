#!/usr/bin/env python
# Fibonacci sequence calculator with dynamic programming:
# Given a number find the nth in the sequence
# Author: Sripathy Ramaswamy
# 07/25/2016

import sys

f = [-1 for x in range(0,45)]

def fib(n):

    if f[n] is -1: 
        f[n] = fib (n -1 ) + fib(n -2 )

    return f[n]

def fib_calc(n):
    f[0] = 0 
    f[1] = 1

    return fib(n)
    
def main():
    n = sys.argv[1]
    print "Input: %s" % n

    y = fib_calc(int(n))
    print "Fibonacci number is: %d " % y 

if __name__ == '__main__':
    main()
