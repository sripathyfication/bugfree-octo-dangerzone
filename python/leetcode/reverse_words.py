#!/usr/bin/env python
# Given a string s= "the sky is blue"
# reverse the string to give
# "blue is sky the"
import sys

words = [] 
specials = [' ', '.', '?', ',', ';', ':', '']

# Just lookup specials and return true if it is a special
# character
def is_special_char(i):
    if i in specials:
        return True
    else:
        return False


def reverse_words():
    r = ''
    words_len = len(words)
    n = words_len - 1
    for i in range(0, words_len):
        r = r + ' ' + words[n]
        n = n - 1

    return r + '.'

def collect_words(n):
    j = 0
    start = 0
    # loop over every char in input string
    # till you find a white space
    for i in n:
        if (is_special_char(i)):
            # Got a word, get it out
            w = n[start:j]
            words.append(w)
            start = j + 1
        j = j + 1

def reversify(i):
    collect_words(i)
    r = reverse_words()
    return r

def main():
    s = sys.argv[1]
    print 'Input string: ' + s
    r = reversify(s)
    print 'Reversed string: ' + r

if __name__=='__main__':
    main()
