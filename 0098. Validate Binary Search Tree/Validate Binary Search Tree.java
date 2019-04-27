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
    public boolean helper(TreeNode node, TreeNode l, TreeNode r) {
        if (node == null) return true;
        if ((l != null && node.val <= l.val) || (r != null && node.val >= r.val))
            return false;
        return helper(node.left, l, node) && helper(node.right, node, r);
    }
    
    public boolean isValidBST(TreeNode root) {
        return helper(root, null, null);
    }
}