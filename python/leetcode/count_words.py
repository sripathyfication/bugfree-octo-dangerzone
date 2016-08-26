#!/usr/bin/env python
# Given a string this program will read,
# count, the words, and store number
# of words and the occurence count
#
# Author: Sripathy Ramaswamy
# 07/25/2016
#
import sys

words = {}
specials = [' ', '.', '?', ',', ';', ':', '']

# Just lookup specials and return true if it is a special
# character
def is_special_char(i):
    if i in specials:
        return True
    else:
        return False

# This function collects words in a dictionary, along with the frequency
# of occurence
def collect_words(n):
    start = 0
    j = 0
    # loop over every char in input string
    # till you find a white space
    for i in n:
        if (is_special_char(i)):
            # Got a word, get it out
            w = n[start:j]
            # If w exists in words{} then just
            # update its occurence count
            # else add a new entry
            if w in words.keys():
               words[w] = words[w] + 1 
            else:
                words[w] = 1 
            start = j + 1
        j = j + 1    
            
# This function just counts the words in a dictionary and returns
# word count
def count_words():
    word_count = 0
    for w in words.keys():
        word_count = word_count + 1
    return word_count    

def main():
    n = sys.argv[1]
    print "Input string: %s" % n
    collect_words(n)
    w = count_words()
    print "Total words: %d " % w 
    print words

if __name__=='__main__':
    main()
