# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def helper(self, node: TreeNode, l: TreeNode, r: TreeNode) -> bool:
        if node:
            return True
        if (l and l.val >= node.val) or (r and r.val <= node.val):
            return False
        return self.helper(node.left, l, node) and self.helper(node.right, node, r)
    
    def isValidBST(self, root: TreeNode) -> bool:
        return self.helper(root, None, None)