class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordFreq;
        for (auto word : words) wordFreq[word]++;
        
        /**
         * a compare type providing a strict weak ordering.
         * Note that the compare parameter is defined such that it return true
         * if its first argument comes before its second argument in a weak ordering.
         * But because the priority queue outputs largest elements first, the elements
         * the "come before" are acutally output last. That is, the front of the queue
         * contains the "last" element according to the weak ordering imposed by Compare.
         */
        auto cmp = [&wordFreq](string &word1, string &word2) {
            return wordFreq[word1] == wordFreq[word2] ? word1 < word2 : wordFreq[word1] > wordFreq[word2];
        };
        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
        
        for (auto wordCnt : wordFreq) {
            pq.push(wordCnt.first);
            if (pq.size() > k) pq.pop();
        }
        
        vector<string> res;
        while (!pq.empty()) {res.push_back(pq.top()); pq.pop();}
        reverse(res.begin(), res.end());
        return res;
    }
};