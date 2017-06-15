#/usr/bin/python

'''

    move all zeroes to end

'''

def move_zeroes(arr):
    zero = []
    non_zero = []

    for i in arr:
        if i is 0:
            zero.append(i)
        else:
            non_zero.append(i)

    return non_zero + zero


if __name__ == '__main__':
    arr = [6,0,8,9,1,2,3,4,0]
    print arr
    print move_zeroes(arr)
