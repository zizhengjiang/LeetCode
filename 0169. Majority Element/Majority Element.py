class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        res, cnt = 0, 0;
        
        for num in nums:
            if cnt == 0:
                res, cnt = num, cnt + 1
            elif res == num:
                cnt += 1
            else:
                cnt -= 1
            
        return res