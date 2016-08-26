#!/usr/bin/env python
# Fibonacci sequence calculator:
# Given a number find the nth in the sequence
# Author: Sripathy Ramaswamy
# 07/25/2016

import sys


def fib(n):
    if (n <= 1):
        return n
    else:
        return fib (n -1 ) + fib(n -2 )

def main():
    n = sys.argv[1]
    print "Input: %s" % n

    y = fib(int(n))
    print "Fibonacci number is: %d " % y 

if __name__ == '__main__':
    main()
