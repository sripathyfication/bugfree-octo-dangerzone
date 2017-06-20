#/usr/bin/python

'''
    Given an array, find all pairs with a given difference
'''
def qsort(arr):
    if not arr:
        return arr

    first = arr[0]
    lesser = filter(lambda x: x < first, arr[1:])
    greater = filter(lambda x: x >= first, arr[1:])
    return qsort(lesser) + [first] + qsort(greater)

def find(arr,j):
    for i in arr:
        if i is j:
            return True
    return False

def pair_w_diff_0(arr,k):
    arr = qsort(arr)
    print arr
    ''' For every element in array, add the difference and find that result. If it is present,
    then that's the pair.'''
    for i in range(0,len(arr)):
        j = arr[i] + k
        if find(arr[i+1:],j) is True:
            print arr[i], j
        
def pairs_w_diff_1(arr,k):
    ''' take each element of the array and put it in a hashmap. For each element, add the
        difference and see if that element is present in the hashmap'''
    pairsum = {}
    for i in arr:
        pairsum[i] = "present"
    print pairsum
    for i in arr:
        j = i + k
        if pairsum.has_key(j):
            print i,j

if __name__ == '__main__':
    arr = [4,2,3,-1,0,4,8]
    pairs_w_diff_1(arr,3)
