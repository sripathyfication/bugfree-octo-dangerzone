#!/usr/bin/env python
# Given a number find the factorial and print
# Author: Sripathy Ramaswamy
# 07/25/2016
import sys

def main():
    n = int(sys.argv[1])
    print "Input: %d" % n 

    y = fact(n)
    print "Factorial is %d"  % y

def fact(n):
    if (n <= 1):
        return 1 
    else:
        return n * fact(n - 1)

if __name__ == '__main__':
    main()
