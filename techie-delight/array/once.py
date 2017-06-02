#/usr/bin/python

# there is a list in which elements occur 3 times, except one element.
# find that element that occurs only once.

def qsort(array):
    if not array:
        return array
    first = array[0]
    lesser = filter(lambda x: x < first, array[1:])
    greater = filter(lambda x: x >= first, array[1:])
    return qsort(lesser) + [first] + qsort(greater)

def find_all_elements(array):
    array = qsort(array)
    print array
    for i in range(0, len(array)-1):
        if array[i] == array[i+1]:
            prev = None
            first = 0
        else:
            if first == 1:
                return prev
            else:
                first = 1
                prev = array[i]

if __name__ == '__main__':
    array = [1,1,1,12,11,11,11]
    print array
    print find_all_elements(array)
