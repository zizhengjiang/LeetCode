class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(256, -1);
        int res = 0, st = -1;

        for (int i = 0; i < s.length(); ++i) {
            if (map[s[i]] > st)
                st = map[s[i]];
            map[s[i]] = i;
            res = max(res, i - st);
        }

        return res;
    }
};