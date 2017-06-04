#/usr/bin/python

# Given a string , find longest substring with non repetitive characters"
# 
# Examples:
#
# string = "abcabcbb", output = "abc", length = 3
# string = "bbbbbbb", output = "b", length = 1
# string = "pwwkew", output ="wke", length = 3


def get_substrings(s, seen_list):
    seen = ""
    if s is "":
        seen_list.append(s)
        return

    if len(s) == 1:
        seen_list.append(s)
        s = ""
        return

    for i in range(0,len(s)):
        if s[i] not in seen:
            seen = seen + s[i] 
        else:
            seen_list.append(seen)
            s = s[i:]
            get_substrings(s,seen_list)
            return        
            
def longest_substring(s):
    seen_list = []
    get_substrings(s, seen_list)

    max_ = 0
    max_so_far = 0
    max_index = 0

    for i in range(0,len(seen_list)): 
        max_ = len(seen_list[i])
        if max_ > max_so_far:
            max_so_far = max_
            max_index = i 
    
    print "string " + s + " longest substring is " + seen_list[max_index] + " of length " + str(len(seen_list[max_index])) 



s = "pwwkew"
longest_substring(s)
s = "abcabcbb"
longest_substring(s)
s = "bbbbbba"
longest_substring(s)
