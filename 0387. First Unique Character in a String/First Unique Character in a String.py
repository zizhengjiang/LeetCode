class Solution:
    def firstUniqChar(self, s: str) -> int:
        count = collections.Counter(s)
        res = 0
        
        for ch in s:
            if count[ch] == 1:
                return res
            else:
                res += 1
                
        return -1