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
    private TreeNode helper(int[] preorder, int ps, int pe, int[] inorder, int is, int ie) {
        if (ps > pe || is > ie) return null;
        TreeNode node = new TreeNode(preorder[ps]);
        
        int ind = 0;
        for (int i = is; i <= ie; i++) {
            if (inorder[i] == preorder[ps]) {
                ind = i;
                break;
            }
        }
        
        node.left = helper(preorder, ps + 1, ps + ind - is, inorder, is, ind - 1);
        node.right = helper(preorder, ps + ind - is + 1, pe, inorder, ind + 1, ie);
        
        return node;
    }
    
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return helper(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }
}