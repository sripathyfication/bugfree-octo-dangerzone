#/usr/bin/python

def qsort(a):
    if not a:
        return a
    first = a[0]
    lesser = filter(lambda x : x < first, a[1:])
    greater = filter(lambda x : x > first, a[1:])
    return qsort(lesser) + [first] + qsort(greater)

def merge_arrays(a1,a2):
    return qsort(a1 + a2)

if __name__ == '__main__':
    a1 = [1,3,5,7,9]
    a2 = [2,4,6,8,10]

    print a1
    print a2
    print merge_arrays(a1,a2)



