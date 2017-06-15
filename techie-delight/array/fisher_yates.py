#/usr/bin/python

'''
    Algorithm to do in place shuffle

    fisher yates:


    for i in range(len(arr) -1, 0):
        j = random() % i
        swap(arr[j], arr[i])


    return arr
'''
import random

def fisher_yates(arr):
    if not arr:
        return arr
    
    for i in range((len(arr) -1),0,-1):
        j = random.randint(0,i)
        # swap em
        tmp = arr[i]
        arr[i] = arr[j]
        arr[j] = tmp
    return arr


if __name__ == '__main__':
    arr = [1,2,3,4,5,6,7,8]
    print arr
    print fisher_yates(arr)
