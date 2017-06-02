#/usr/bin/python

def _remove(array, this):
    temp = []
    for i in range(0,len(array)):
        if array[i] != this:
            temp.append(array[i])
    return temp       



if __name__ == '__main__':
    array = [0,1,-1,4,2,0,5,6,7]

    print " removing 0 .. " + str(_remove(array,0))
    print " removing 4 .. " + str(_remove(array,4))
