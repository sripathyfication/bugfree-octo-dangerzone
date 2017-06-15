#/usr/bin/python

''' 
    Given an array with duplicates, find the majority element.

    Majority element is defined as being present greater n/2 times.

    Otherwise, boyer moore fails

    Algorithm:

    arr[0] = cur max
    give it 1 vote.
    If next element is cur max, give it a vote.
    If not decrement vote.
    if vote becomes 0, then curr max = arr[index where it becomes 0]
'''
def qsort(arr):
    if not arr:
        return arr
    first = arr[0]
    lesser = filter (lambda x: x < first, arr[1:])
    greater = filter (lambda x: x >= first, arr[1:])
    return qsort(lesser) + [first] + qsort(greater)

def boyer_moore(arr):
    arr = qsort(arr)

    curr_max = 0
    vote = 0

    for i in arr:
        if vote is 0:
            curr_max = i
            vote +=1
        else:    
            if i is curr_max:
                vote += 1
            else:
                vote -= 1
    return curr_max



if __name__ == '__main__':
    arr = [6,1,2,3,0,0,2,0,0,0,0]
    print arr
    majority_elem = boyer_moore(arr)
    print " Majority element is " + str(majority_elem)
