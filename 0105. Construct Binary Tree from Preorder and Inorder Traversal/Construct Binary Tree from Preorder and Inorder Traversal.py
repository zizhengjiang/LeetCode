# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def helper(self, preorder: List[int], preSt: int, preEd: int, inorder: List[int], inSt: int, inEd: int) -> TreeNode:
        if preSt > preEd or inSt > inEd:
            return None
        
        node = TreeNode(preorder[preSt])
        idx = inorder.index(preorder[preSt])
        
        node.left = self.helper(preorder, preSt + 1, preSt + idx - inSt, inorder, inSt, idx - 1)
        node.right = self.helper(preorder, preSt + idx - inSt + 1, preEd, inorder, idx + 1, inEd)
        
        return node
    
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        return self.helper(preorder, 0, len(preorder) - 1, inorder, 0, len(inorder) - 1)