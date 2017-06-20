#/usr/bin/python

'''
    Given an array, find the maximum sum sub array
    We can do this in place, using Kadane's algorithm
'''

def max_sum_subarray(array):
    max_so_far = max_ending_here = 0
    for i in arr:
        max_ending_here = max_ending_here + i
        if max_ending_here < 0:
            max_ending_here = 0
        if max_so_far < max_ending_here:
            max_so_far = max_ending_here
    return max_so_far

if __name__ == '__main__':
    arr = [-2,-1,0,1,2,5,-3]
    print max_sum_subarray(arr)

