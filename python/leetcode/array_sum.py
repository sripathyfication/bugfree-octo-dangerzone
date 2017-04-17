#!/usr/bin/python
import sys
# to change input, change the array below
arr = [10,4,2,3,5]
def sum_array():
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

    

    
if __name__=='__main__':
    sum_array();
