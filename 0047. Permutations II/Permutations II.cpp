class Solution {
    void backtracking(vector<int> &nums, vector<int> &tmp, vector<vector<int>> &res, vector<bool> &visited) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                // visited[i - 1] is false means that the number is already used in the previous recursion
                if (visited[i] || i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
                visited[i] = true;
                tmp.push_back(nums[i]);
                backtracking(nums, tmp, res, visited);
                visited[i] = false;
                tmp.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        backtracking(nums, tmp, res, visited);
        return res;
    }
};