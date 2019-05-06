class TrieNode {
    public boolean end;
    public TrieNode[] next;
    public TrieNode() {
        end = false;
        next = new TrieNode[26];
    }
}

class Solution {
    private void buildTrie(String[] words, TrieNode root) {
        for (String word : words) {
            TrieNode tmp = root;
            for (char ch : word.toCharArray()) {
                if (tmp.next[ch - 'a'] == null) tmp.next[ch - 'a'] = new TrieNode();
                tmp = tmp.next[ch - 'a'];
            }
            tmp.end = true;
        }
    }
    
    private boolean search(TrieNode root, String word, int idx, int cnt) {
        if (idx == word.length()) return false;
        TrieNode tmp = root;
        for (int i = idx; i < word.length(); i++) {
            char ch = word.charAt(i);
            if (tmp.next[ch - 'a'] == null) return false;
            if (tmp.next[ch - 'a'].end) {
                if (i == word.length() - 1) return cnt >= 1;
                if (search(root, word, i + 1, cnt + 1)) return true;
            }
            tmp = tmp.next[ch - 'a'];
        }
        return false;
    }
    
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        List<String> res = new ArrayList();
        if (words == null || words.length <= 1) return res;
        TrieNode root = new TrieNode();
        buildTrie(words, root);
        for (String word : words) {
            if (search(root, word, 0, 0)) {
                res.add(word);
            }
        }
        return res;
    }
}

class Solution {
    private static boolean canForm(String word, Set<String> dict) {
        if (dict.isEmpty()) return false;
        boolean[] dp = new boolean[word.length() + 1];
        dp[0] = true;
        for (int i = 1; i <= word.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.contains(word.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[word.length()];
    }
    
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        List<String> res = new ArrayList();
        Set<String> preWords = new HashSet();
        Arrays.sort(words, (w1, w2) -> w1.length() - w2.length());
        
        for (int i = 0; i < words.length; i++) {
            if (canForm(words[i], preWords)) {
                res.add(words[i]);
            }
            preWords.add(words[i]);
        }
        
        return res;
    }
}