class Solution {
    void addNextWord(string &word, unordered_set<string> &us, queue<string> &q) {
        for (auto &ch : word) {
            char tmp = ch;
            for (int i = 0; i < 26; i++) {
                ch = 'a' + i;
                if (us.find(word) != us.end()) {
                    q.push(word);
                    us.erase(word);
                }
            }
            ch = tmp;
        }
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> us{wordList.begin(), wordList.end()};
        queue<string> q;
        q.push(beginWord);
        int res = 1;
        
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                string tmp = q.front();
                q.pop();
                if (tmp == endWord) return res;
                addNextWord(tmp, us, q);
            }
            res++;
        }
        
        return 0;
    }
};