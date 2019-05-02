class Solution {
    void backtracking(vector<int>& nums, vector<int> &tmp, vector<vector<int>> &res) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (find(tmp.begin(), tmp.end(), nums[i]) != tmp.end()) continue;
                tmp.push_back(nums[i]);
                backtracking(nums, tmp, res);
                tmp.pop_back();
            }
        }
    } 
        
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> res;
        backtracking(nums, tmp, res);
        return res;
    }
};
