/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
    
    int dfs(TreeNode *root, int &res) {
        if (!root) return 0;
        int l = dfs(root->left, res);
        int r = dfs(root->right, res);
        
        res = max(res, root->val + l + r);
        return max(root->val + max(l, r), 0);
    }
};