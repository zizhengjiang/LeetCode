class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d, st, res = {}, -1, 0;
        for i in range(len(s)):
            if s[i] in d and d[s[i]] > st:
                st = d[s[i]]
            d[s[i]] = i
            res = max(res, i - st)
        return res;