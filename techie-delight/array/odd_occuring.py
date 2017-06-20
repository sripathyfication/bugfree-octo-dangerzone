#/usr/bin/python


'''
Given an array, find all elements that occur an odd number of times.
The array has duplicates with each duplicate appearing even number of times.
'''

def odd_occuring_element(arr):
    count_frequency = {}
    
    for i in arr:
        if count_frequency.has_key(i):
            count_frequency[i] += 1 # count_frequency[i] + 1
        else:    
            count_frequency[i] = 1 
    print arr
    print count_frequency


if __name__ == '__main__':
    arr = [-1,2,0,-1,3,2,0,4]
    odd_occuring_element(arr)
