#/usr/bin/python

'''
 Given an array containing only 0,1,2 return it sorted
 '''


def dutch_national_flag(arr):
    zero = []
    one = []
    two = []

    for i in arr:
        if i is 0:
            zero.append(i)
        if i is 1:
            one.append(i)
        if i is 2:
            two.append(i)
    return zero + one + two

if __name__ == '__main__':

    arr = [0,1,0,2,1,1,0]
    print arr
    print dutch_national_flag(arr)
