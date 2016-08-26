#!/usr/bin/env python
'''
Largest subarray equal to a sum.
Given an array of integers
'''
import sys

def sum_of_array(s_a):
    sum_ = 0
    for i in range(0,len(s_a)):
        sum_ = sum_ + s_a[i]
    return sum_

def max_length(s_arr,a,k):
    print s_arr
    print a
    print k
    if len(s_arr) is 0:
        s_arr.append(a[0])
    for i in range(1,len(a)):
        sum_ = sum_of_array(s_arr)
        print '--------'
        print sum_
        print s_arr
        print a[i]
        if (sum_ + a[i] < k):
            s_arr.append(a[i])
        elif (sum_ + a[i] == k):
            s_arr.append(a[i])
            return len(s_arr)
        elif (sum_ + a[i] > k):
            s_arr.pop()

def main():
    s_arr=[]
    a = [1,2,3,4]
    k = 2
    l = max_length(s_arr,a,k)
    print l

if __name__=='__main__':
    main()
