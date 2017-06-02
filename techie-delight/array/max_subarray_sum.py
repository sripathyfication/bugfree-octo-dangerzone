#/usr/bin/python

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
