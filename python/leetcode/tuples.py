#!/usr/bin/env python
import sys

def main():
    sripathy = ("Sripathy Ramaswamy",1982)
    sripathy + ("Shrikanth Ramaswamy", 1985) + sripathy[5:]
    print sripathy[:3]
    print sripathy

if __name__== '__main__':
    main()
