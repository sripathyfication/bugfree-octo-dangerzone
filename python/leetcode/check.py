#!/usr/bin/python
import sys

def check(c, inp):
    for i in range(0,(len(inp) -1)):
        if c in inp[i:]:
            print "yes"
        else:
            print "no"

def main():
    inp = raw_input("Enter string\n")
    c = raw_input("Enter char\n")
    check(c,inp)


if __name__=='__main__':
    main()
