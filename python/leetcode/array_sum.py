#!/usr/bin/python
import sys
from timer import PyTimer
# to change input, change the array below
arr = [1,5,7,0,10,4,2,3,5,12,34,23,44,45,54,56,66,65,77,67,76,88,14,90]

def naive_sum_array():
    print arr
    if (len(arr)) is 0:
        print "Array has no elements"
        return

    s = sys.argv[1]
    for i in range(0,len(arr)):
        for j in range(i+1,len(arr)):
            if ((arr[i] + arr[j]) == int(s)):
                print " Sum " + s + " is  present at " + str(i) +  " and " +str(j)
                return
    print " Sum not present"
    return

def diff_sum_array():
    print arr

    if (len(arr)) is 0:
        print "Array has no elements"
        return
    
    s = sys.argv[1]
    for i in range(0, len(arr)):
        d = int(s) - arr[i] 
        # now search for d in the arr[i+ 1] to end of array and repeat
        for j in range(i+1,len(arr)):
            if d == arr[j]: 
               print " Sum " + s + " is  present at " + str(i) +  " and " +str(j)
               return 
    print " Sum not present"
    return

    
if __name__=='__main__':
    with PyTimer(True) as t:
        naive_sum_array();
        print "naive method"
    with PyTimer(True) as t:    
        diff_sum_array();
        print "diff method"
    
