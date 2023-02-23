class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = (int) profits.size();
        priority_queue<int> pq;
        vector<pair<int, int>> comb(n);
        
        for (int i = 0; i < n; i++) {
            comb[i] = {capital[i], profits[i]};
        }
        
        sort(comb.begin(), comb.end());
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && k > 0 && w < comb[i].first) {
                w += pq.top(); pq.pop();
                k--;
            }
            if (w >= comb[i].first) pq.push(comb[i].second);
        }
        
        while (!pq.empty() && k > 0) {
            w += pq.top(); pq.pop();
            k--;
        }
        
        return w;
    }
};
