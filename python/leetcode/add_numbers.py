#!/usr/bin/env python
import sys


def sum_lists(inp_1, inp_2):
    res = []
    # what to do if they're of different sizes
    len_ = len(inp_1) if (len(inp_1) > len(inp_2)) else len( inp_2)
    
    for i in range(0,len_ - 1):
        print i
        x = inp_1[i]
        y = inp_2[i]
        res[i] = x + y
    return res    

def main():
    inp_1 = [1,2,3]
    inp_2 = [2,7,8,9]
    res = sum_lists(inp_1, inp_2)
    print res

if __name__ == '__main__':
    main()
