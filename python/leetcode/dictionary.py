#!/usr/bin/python
import sys

dict = {
    1:{'120': True},
    2:{'121': True, '122':False},
}

def main():
    for key,value in dict.iteritems():
        for k,v in value.iteritems():
            print k,v

if __name__=='__main__':
   main()
