#!/usr/bin/python

import sys

def count(n):
    count = 0
    print n 
    size = sys.getsizeof(n)
    while size:
       if n & 1:
          count = count + 1
       n = n >> 1 
       size = size -1
    return count

def main():
    n = input("Enter the number of your choice\n")
    bits = [0 for x in range(0,n+1)]
    for i in range(1,n+1):
        bits[i] = count(i)
    print bits

if __name__ == '__main__':
    main()
