#!/usr/bin/env python
import sys
from collections import deque

delimiters=['*','+']
numbers=['0','1','2','3','4','5','6','7','8','9']
nums=deque([])
opers=deque([])
r_pol=deque([])
operand=deque([])

def stringify():
    r_str = ''
    while len(r_pol):
        r_str = r_str + r_pol.popleft()
    return r_str        

'''
 parse input string
 look for arithmetic
 operations, fill nums
'''
def fill_nums(str):
    start = 0
    i = 0
    for x in str:
        if x in numbers:
           n = str[start:i+1]
           nums.append(n)
           start = i + 1  

        elif x in delimiters:
           n = str[start:i+1]
           opers.append(n)
           start = i + 1  
        i = i + 1


def reverse_polish():
    print 'Begin:'
    print '-----:'
    print "Length of nums is %d " % len(nums)
    print "Length of opers is %d " % len(opers)
    print "Length of r_pol is %d " % len(r_pol)
    print "Length of operand is %d " % len(operand)
    print nums
    print opers
    print r_pol 
    print operand
    print '-----'
    if len(nums) and len(opers):
        n = nums.popleft()
        print n 
        o = opers.popleft()
        print o
        if o is '*':
           r_pol.append(n)
           operand.append(o)
           reverse_polish()
        if o is '+':
           r_pol.append(n)
           while (len(operand) > 0):
               op = operand.pop()
               if op is '+':
                  operand.append(op)
                  break
               else:
                  r_pol.append(op)
           operand.append(o)
           reverse_polish()

    if (len(opers) is 0):
       if len(nums) > 0:
           r_pol.append(nums.popleft())
           while (len(operand) > 0):
               r_pol.append(operand.pop())

        
def main():
    inp_str = '2*4*3*9*3*5'
    fill_nums(inp_str)
    reverse_polish()
#    print r_pol
    r_str = stringify()
    print r_str

if __name__=='__main__':
    main()
              
