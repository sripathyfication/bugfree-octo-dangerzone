#/usr/bin/python

'''
    Given an array of integers, find the maximum element.

    Using the boyer moore vote algoithm, we can find the majority
    element in place and in linear time.

    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    NOTE: The input array to boyer moore has to be sorted without which it wont work
    --------------------------------------------------------------------------------

    Algorithm:
    ~~~~~~~~~
    1. assume majority is arr[0]; give it 1 vote
    2. for every element in array, if element is equal to majority element, increment vote
    else decrement vote.
    3.return majority element

    Runtime analysis:
    ~~~~~~~~~~~~~~~~

    sorting an unsorted array would take O(log n)
    finding majority element takes O(n)
    so total runtime is O(logn + n) which is ~O(n)
'''
def qsort(array):
    if not array:
        return array
    first = array[0]
    lesser = filter(lambda x: x < first, array[1:])
    greater = filter(lambda x: x >= first, array[1:])
    return qsort(lesser) + [first] + qsort(greater)

def boyer_moore_vote(array):
    array = qsort(array)
    print "input after sort: " 
    print array
    majority = 0
    vote = 0
    for x in array:
        if vote == 0:
            majority = x
            vote +=1
        else:
            if x == majority:
                vote = vote + 1
            else:
                vote = vote - 1
    return majority

if __name__ == '__main__':
    array = [8,8,3,2,1,4,9]    
    print array
    print " majority element is " + str(boyer_moore_vote(array))


