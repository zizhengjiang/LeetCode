class TrieNode {
public:
    bool end;
    vector<TrieNode*> next;
    
    TrieNode() : end{false}, next{26, nullptr} {}
    ~TrieNode() {
        for (auto ele : next) delete ele;
    }
};

class Solution {
    void buildTrie(vector<string> &words, TrieNode *root) {
        for (auto word : words) {
            TrieNode *tmp = root;
            for (auto ch : word) {
                if (!tmp->next[ch - 'a']) tmp->next[ch - 'a'] = new TrieNode();
                tmp = tmp->next[ch - 'a'];
            }
            tmp->end = true;
        }
    }
    
    bool search(TrieNode *root, string &word, int idx, int cnt) {
        if (idx == word.size()) return false;
        TrieNode *tmp = root;
        for (int i = idx; i < word.size(); i++) {
            if (!tmp->next[word[i] - 'a']) return false;
            if (tmp->next[word[i] - 'a']->end) {
                if (i == word.length() - 1) return cnt >= 1;
                if (search(root, word, i + 1, cnt + 1)) return true;
            }
            tmp = tmp->next[word[i] - 'a'];
        }
        return false;
    }
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        if (words.size() <= 1) return res;
        TrieNode *root = new TrieNode();
        buildTrie(words, root);
        for (auto word : words) {
            if (search(root, word, 0, 0)) {
                res.push_back(word);
            }
        }
        return res;
    }
};

class Solution {
    bool canForm(string &word, unordered_set<string> &dict) {
        if (dict.empty()) return false;
        vector<bool> dp(word.size() + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= word.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.find(word.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[word.size()];
    }
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> us{words.begin(), words.end()};
        vector<string> res;
        unordered_set<string> preWords;
        sort(words.begin(), words.end(), [](string &w1, string &w2) {return w1.size() < w2.size();});
        
        for (int i = 0; i < words.size(); i++) {
            if (canForm(words[i], preWords)) {
                res.push_back(words[i]);
            }
            preWords.insert(words[i]);
        }
        
        return res;
    }
};