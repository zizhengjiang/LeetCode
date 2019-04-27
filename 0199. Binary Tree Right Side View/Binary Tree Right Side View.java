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
    private void dfs(TreeNode node, List<Integer> res, int depth) {
        if (node == null) return;
        
        if (res.size() == depth) {
            res.add(node.val);
        }
        
        dfs(node.right, res, depth + 1);
        dfs(node.left, res, depth + 1);
    }
    
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        dfs(root, res, 0);
        return res;
    }
}