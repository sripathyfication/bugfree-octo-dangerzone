#/usr/bin/python

def rotate(array, k):
    new = array[k:] 
    for i in range(0,k):
        new.append(array[i])
    return new

if __name__ == '__main__':
    array = [1,2,3,4,5,6]
    k = 5 
    print k, array
    print rotate(array, k)
