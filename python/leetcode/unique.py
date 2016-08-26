#!/usr/bin/env python
import sys

def unique(inp):
    for i in range(0,len(inp) -1):
        old = inp[i:i+1] 
        new = inp[i+1:i+2]
        if new is not old:
           return i+1
        
    return -1
        
def main():
    inp = raw_input("Enter your string:\n")
    index = unique(inp)
    print index

if __name__ == '__main__':
    main()
