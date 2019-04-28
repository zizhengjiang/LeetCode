class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res, cnt = 0;
        
        for (auto num : nums) {
            if (cnt == 0) cnt++, res = num;
            else if (res == num) cnt++;
            else cnt--;
        }
        
        return res;
    }
};