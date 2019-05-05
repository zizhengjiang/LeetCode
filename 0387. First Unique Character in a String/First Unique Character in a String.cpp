class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> alpha(26, 0);
        for (auto ch : s) alpha[ch - 'a']++;
        for (int i = 0; i < s.length(); i++)
            if (alpha[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};