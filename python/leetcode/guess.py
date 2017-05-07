#!/usr/bin/env python
import random
import math

user_input = 0
def guess(g):
    if g is user_input:
       return 0
    elif g < user_input:
       return -1
    elif g > user_input:
       return 1

def guessNum(n):
    my_g = random.random(1,n)
    while r is not 0:
        r = guess(my_g)
        if r > 0:
           r = random.random(1,my_g)
        elif r < 0:
           r = random.random(my_g,n)   
        elif r is 0:
           print "You number is %d" % my_g
           return

def main():
    n = raw_input("Pick a number from 1 to 25\n")
    user_input = n
    print "Trying to guess your number..\n"
    guessNum(n)
        
if __name__ == '__main__':
    main()
