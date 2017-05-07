#!/usr/bin/env python
import sys
# In leetcode, e = 1 is the index of the first
# repeating char. l = 0 is the index of the first
# non repeating.
def unique(inp):
    not_found = -1
    for i in range(0,len(inp)-1):
        ch = inp[i:i+1] 
        print ch
        r = i + 1
        for j in range(r, (len(inp) - 1)):
            print inp[j:]
            if ch not in inp[j:]:
               if i is not 0:
                  not_found = i
               break
            else:
               break
    return -1 
        
def main():
    inp = raw_input("Enter your string:\n")
    index = unique(inp)
    print index

if __name__ == '__main__':
    main()
