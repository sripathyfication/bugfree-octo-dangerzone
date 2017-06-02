#/usr/bin/python

# Kadane's algorithm:
#
# going over the array only once but remembering the previous result.
# rudimentary form of dynamic programming
#
# compute a max on every iteration starting with 0
# if max is less than 0, that means there was a negative number
# reset it to 0
# if not then check against max_sum_so_far:
# if max is greater than that, make max_sum_so_far = max
#
# return max_sum_so_far

def max_sum_subarray(array):
    max_ = 0
    max_so_far = 0
    print array
    for i in range(0,len(array)):
        max_ = max_ + array[i]
        if max_ < 0:
            max_ = 0
        else:
            if max_ > max_so_far:
                max_so_far = max_

    return max_so_far    


if __name__ == '__main__':
    array = [13,1,2,4,-1,-2,0]
    print max_sum_subarray(array)
