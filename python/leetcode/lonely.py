#!/usr/bin/env python
import math

def even(a):
    if a % 2 is 0:
       return True
    else:
       return False

def lonelyinteger(a):
    a.sort() 
    i = 0
    answer = 0

    '''
    If the number of elements in the array is even, 
    then there can't be a lonely integer
    '''
    if even(len(a)):
       return answer 
    '''
    take every element and subtract with next element
    '''
    while i is not len(a):
        if i is (len(a) -1 ) and answer is 0:
            answer = a[i] 
            return answer
        if (a[i] - a[i+1]) is not 0:
            answer = a[i]
            i = i + 2
        else:
            i = i + 2
    return answer

if __name__ == '__main__':
    a = input()
    b = map(int, raw_input().strip().split(" "))
    print lonelyinteger(b)
