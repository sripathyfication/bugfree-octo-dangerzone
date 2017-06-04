#/usr/bin/python

# Given a string , find longest substring with non repetitive characters"
# 
# Examples:
#
# string = "abcabcbb", output = "abc", length = 3
# string = "bbbbbbb", output = "b", length = 1
# string = "pwwkew", output ="wke", length = 3
# string = "dvdf", output = "vdf", length = 3


class Solution(object):
    def get_substrings(self,s):
        seen = ""
        if s is "":
            return 0
        for c in s:
            if c not in seen:
                seen = seen + c
            else:
                break
        return len(seen)
                
    def longest_substring(self,s):
        max_ = 0
        max_so_far = 0
        while s is not "":
            max_ = self.get_substrings(s)
            if max_ > max_so_far:
                max_so_far = max_
            s = s[1:]
        return max_so_far


s = "abcabcbb"
print "Test case 2: string " + s
sol = Solution()
print sol.longest_substring(s)
s = "pwwkew"
print "Test case 1: string " + s
print sol.longest_substring(s)
s = "bbbbbba"
print "Test case 3: string " + s
print sol.longest_substring(s)
s = "dvdf"
print "Test case 4: string " + s
print sol.longest_substring(s)
