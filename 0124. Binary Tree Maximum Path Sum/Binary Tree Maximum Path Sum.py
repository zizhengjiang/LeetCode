# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.res = float('-inf')
        
    def helper(self, node: TreeNode) -> int:
        if not node:
            return 0;
        
        l = self.helper(node.left)
        r = self.helper(node.right)
        
        self.res = max(self.res, l + r + node.val)
        return max(0, max(l, r) + node.val)
    
    def maxPathSum(self, root: TreeNode) -> int:
        self.helper(root)
        return self.res