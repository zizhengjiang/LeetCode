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
    bool helper(TreeNode *node, TreeNode *l, TreeNode *r) {
        if (!node) return true;
        if ((l && node->val <= l->val) || (r && node->val >= r->val))
            return false;
        return helper(node->left, l, node) && helper(node->right, node, r);
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, nullptr, nullptr);
    }
};