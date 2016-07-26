#!/usr/bin/env python
# Given an array, find the peak element.
# E.g. [1,2,3,1] 3 is the peak element,
# so return index 2
# Peak element is defined as a number that is
# greater than its neighbors
#
# Author: Sripathy Ramaswamy
# 07/25/2016
import sys

def peak_element(nums):
    peak = 0
    nums_len = len(nums)

    # special cases
    if nums_len is 0:
        return None

    if nums_len is 1:
        return 0 

    # Regualar cases
    for i in range(0, nums_len):
        if ((i+1) < nums_len): 
            if (nums[i] > nums[i-1]) and (nums[i] > nums[i+1]):
                return i
        else:       
            return i    


def main():
    peak = 0
    numbers = [1,2,3]
    peak = peak_element(numbers)
    print peak

if __name__ == '__main__':
    main()
