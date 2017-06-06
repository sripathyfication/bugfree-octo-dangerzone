
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_ = 0
        max_so_far = 0
        while s is not "":
            max_ = self.get_substrings(s)
            if max_ > max_so_far:
                max_so_far = max_
            print s
            s = s[1:]

        return max_so_far
                                                
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


sol = Solution()
print sol.lengthOfLongestSubstring("abcabcbb")
