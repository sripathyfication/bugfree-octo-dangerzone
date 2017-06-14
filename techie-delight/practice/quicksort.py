#/usr/bin/python

'''
    Best Quicksort implementation ever.

    Assume a pivot as arr[0]
    grab all elements in array less than arr[0] in a different array called lesser
    grab all elements in array greater than arr[0] in a another array called greater.

    so assume an array 1,2,5,0,3,4

    pivot = 1
    lesser = 0
    greater = 2,5,3,4

    return qsort(lesser) + [pivot] + qsort(greater) 
'''

def quicksort(arr):
    if not arr:
        return arr

    pivot = arr[0]
    lesser = filter(lambda x: x < pivot, arr[1:])
    greater = filter(lambda x: x >= pivot, arr[1:])
    return quicksort(lesser) + [pivot] + quicksort(greater)


if __name__ == '__main__':
    arr = [1,2,3,4,5,6,7,1,2,3,4,5,6,7,4,5,6,7,8,9,10,4,5,6,7,8,9,10,0,4,5,6,7,8,9,10]
    print arr
    arr = quicksort(arr)
    print arr
