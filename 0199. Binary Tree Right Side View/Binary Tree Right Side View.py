# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, node: TreeNode, res: List[int], depth: int) -> None:
        if node is None:
            return
        if len(res) == depth:
            res.append(node.val)
            
        self.dfs(node.right, res, depth + 1)
        self.dfs(node.left, res, depth + 1)
        
    def rightSideView(self, root: TreeNode) -> List[int]:
        res = list()
        self.dfs(root, res, 0)
        return res