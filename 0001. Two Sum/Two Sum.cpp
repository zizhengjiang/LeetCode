class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); ++i) {
            if (um.find(nums[i]) != um.end())
                return {um[nums[i]], i};
            um[target - nums[i]] = i;
        }
        return {-1, -1};
    }
};