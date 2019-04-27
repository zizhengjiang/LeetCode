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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                auto tmp = q.front();
                q.pop();
                
                if (i == s - 1) res.push_back(tmp->val);
                
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
        
        return res;
    }
};

class Solution {
    void dfs(TreeNode *node, vector<int> &res, int depth) {
        if (!node) return;
        if (res.size() == depth) {
            res.push_back(node->val);
        }
        dfs(node->right, res, depth + 1);
        dfs(node->left, res, depth + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
};