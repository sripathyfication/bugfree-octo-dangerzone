#/usr/bin/python

'''
    Trick to converting upper case to lower case:

    ch | ' '

    Trick to converting lower case to upper case:

    ch & '_'


    Trick to finding a letter's position in the alphabet (userful in Trie problems)

    ch & 31
'''

def _to_upper(char):
    return (int(char) | int(' '))

def _to_lower(char):
    return (char & '_')


def _to_index(char):
    return (char & 31)



print _to_upper('a')
print _to_lower('A')
print _to_index('a')

    
