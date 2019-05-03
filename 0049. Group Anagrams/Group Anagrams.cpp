/**
 * follow up: what if the input string is very large?
 * using an array count the number of occurrences of each letter and then compare.
 * code implementation: .py file
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        
        for (auto str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            um[tmp].push_back(str);
        }
        
        vector<vector<string>> res;
        for (auto ele : um) {
            res.push_back(ele.second);
        }
        
        return res;
    }
};