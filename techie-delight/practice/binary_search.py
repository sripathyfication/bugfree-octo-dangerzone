#/usr/bin/python

'''
    Given a sorted array and element, find the element in the array. If not sorted, sort first.
'''
def qsort(arr):
    if not arr:
        return arr
    first = arr[0]
    lesser = filter(lambda x: x < first, arr[1:])
    greater = filter(lambda x: x >= first, arr[1:])
    return qsort(lesser) + [first] + qsort(greater)

def bin_search(arr, elem):
    mid_ = len(arr)/2
    if not arr:
        return False
    if elem == arr[mid_]:
        return True
    if elem > arr[mid_]:
        return bin_search(arr[mid_+1:], elem)
    else:
        return bin_search(arr[:mid_], elem)
    return False       

if __name__ == '__main__':
    arr = [4,2,6,8,1,0,9]
    find = 0 
    arr = qsort(arr)
    print arr
    found = bin_search(arr,find)
    if found is False:
        print "Element : " + str(find) + " not found"
    else:
        print "Element : " + str(find) + " found "
