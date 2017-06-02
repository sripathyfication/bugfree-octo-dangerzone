#/usr/bin/python

def qsort(a1):
    if not a1:
        return a1
    first = a1[0]
    lesser = filter(lambda x: x < first, a1[1:])
    greater = filter(lambda x: x > first, a1[1:])
    return qsort(lesser) + [first] + qsort(greater)

def remove_dupes(a1):
    #first sort the array
    a1 = qsort(a1)
    prev = None
    for i in a1:
        if i is prev:
            a1.remove(i) 
        prev = i
    return a1

def remove_dupes_faster(a1):
    a2 = [None] * len(a1)
    for i in a1:
        if a2[i] is None:
            a2[i] = i
    return a2    

if __name__ == '__main__':
    a1 = [3,4,2,2,1,5,6,1,7,1,3,4,2,2,1,5,6,1,7,1,3,4,2,2,1,5,6,1,7,1,3,4,2,2,1,5,6,1,7,1,3,4,2,2,1,5,6,1,7,1]
    print a1
    print remove_dupes(a1)
# print remove_dupes_faster(a1)
        
