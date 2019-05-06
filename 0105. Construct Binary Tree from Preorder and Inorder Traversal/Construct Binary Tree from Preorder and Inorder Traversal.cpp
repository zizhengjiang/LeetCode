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
    TreeNode *helper(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie) {
        if (ps > pe || is > ie) return nullptr;
        TreeNode *root = new TreeNode(preorder[ps]);
        
        int ind;
        for (int i = is; i <= ie; i++) {
            if (inorder[i] == preorder[ps]) {
                ind = i;
                break;
            }
        }
        
        root->left = helper(preorder, ps + 1, ps + ind - is, inorder, is, ind - 1);
        root->right = helper(preorder, ps + ind - is + 1, pe, inorder, ind + 1, ie);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};