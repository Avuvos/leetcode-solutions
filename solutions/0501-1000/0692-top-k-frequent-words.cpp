class Compare {
public:
    bool operator() (const pair<int, string> &p1, const pair<int, string> &p2) {
        if (p1.first != p2.first) return p1.first > p2.first;
        return p1.second < p2.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (auto word: words) {
            count[word]++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        for (auto [word, amount]: count) {
            pq.push({amount, word});
            if (pq.size() > k) pq.pop();
        }
        
        vector<string> ans;
        while (!pq.empty()) {
            string current = pq.top().second;
            pq.pop();
            ans.push_back(current);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
