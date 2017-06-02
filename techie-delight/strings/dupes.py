#/usr/bin/python
from trie import Trie

def dupes(string):
    list_ = []
    for c in string:
        if c not in list_:
            list_.append(c)
    return list_

def print_list(l):
    c_ = ''
    for i in l:
        c_ = c_ + i
    print c_

if __name__ == '__main__':
    string = "srripathhy"
    print "removing dupes in.. " + string
    l_ = dupes(string)
    print_list(l_)
