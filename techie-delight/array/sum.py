#/usr/bin/python

def array_sum(arr,sum_):
    for i in range(0,len(arr)):
        print i
        for j in range(i+1,len(arr)):
            if arr[i] == (sum_ - arr[j]):
                return i,j
            elif (sum_ - arr[i]) == arr[j]:    
                return i,j
    return None
                
def array_sum_fast(arr, sum_):
    new_ = filter(lambda x: for i in range(0,len(arr): x = sum_ - arr[], 
if __name__ =='__main__':
    arr = [1] * 100000
    print array_sum(arr, 1)
