#!/usr/bin/python

l1 = [9,1,4,5,6]
l2 = [2,3,1,5,6]

def list_add():
    print l1
    print l2
    rem = 0
    r = []
    for i in range(0,len(l1)):
        e1 = l1[i]
        e2 = l2[i]
        s = e1 + e2
        s = s + rem

        print rem
        if ((s % 10) > 0):
            rem = s % 10
            x = s /10
            r.append(x)
        else:
            rem = 0
            x = s/10;
            r.append(x)
        
    if (rem):
        r.append(rem)
        
    print r


if __name__=="__main__":
   list_add();
