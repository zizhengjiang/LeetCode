/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    int res = Integer.MIN_VALUE;
    
    private int helper(TreeNode node) {
        if (node == null) return 0;
        int l = helper(node.left);
        int r = helper(node.right);
        
        res = Math.max(res, l + r + node.val);
        return Math.max(0, Math.max(l, r) + node.val);
    }
    
    public int maxPathSum(TreeNode root) {
        helper(root);
        return res;
    }
}