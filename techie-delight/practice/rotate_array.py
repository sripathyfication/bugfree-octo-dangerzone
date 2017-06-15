#/usr/bin/python

'''
    Given an array and a rotation factor, rotate the array by that much and return.

    E.g. array = [1,2,3,4,5,6] rf = 2
        return array = [5,6,1,2,3,4]

        array = [1,2,3,4,5,6,7,8]
        rf = 4
        return = [5,6,7,8,1,2,3,4]
'''
def rotate_array(arr, rf):
    if not arr:
        return arr
    print rf
    count = rf
    while count:
        for i in range(0,len(arr)):
            for j in range(len(arr),1): 
                tmp = arr[j]
                arr[j] = arr[i]
                arr[i] = tmp
        count -=1
    return arr                

if __name__ == '__main__':
    arr = [1,2,3,4,5,6,7,8]
    print arr
    ret = rotate_array(arr,1)
    print ret

