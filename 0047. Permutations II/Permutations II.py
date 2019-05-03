class Solution:
    def backtracking(self, nums: List[int], tmp: List[int], res: List[List[int]], visited: List[int]) -> List[List[int]]:
        if len(nums) == len(tmp):
            res.append(tmp[:])
        else:
            for i in range(len(nums)):
                if visited[i] or i > 0 and nums[i - 1] == nums[i] and visited[i - 1] is False:
                    continue
                visited[i] = True
                tmp.append(nums[i])
                self.backtracking(nums, tmp, res, visited)
                visited[i] = False
                tmp.pop()
    
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res, tmp, visited = list(), list(), [False for i in range(len(nums))]
        self.backtracking(nums, tmp, res, visited)
        return res