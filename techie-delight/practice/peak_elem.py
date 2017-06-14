#/usr/bin/python

'''
    Find peak element in an unsorted array.
    A peak element is the element that is greater than it's neighbors
'''

def peak_elem(arr):
    max_ = 0
    max_so_far = 0
    for i in arr:
        max_ = i 
        if max_ > max_so_far:
            max_so_far = max_
    return max_so_far


if __name__ == '__main__':
    arr = [2,4,5,7,8]
    print peak_elem(arr)
