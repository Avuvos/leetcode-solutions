class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long mx = 0;
        long long mn = 0;
        
        priority_queue<int> pq_max;
        priority_queue<int, vector<int>, greater<>> pq_min;
        vector<int> a;
        for (int i = 0; i < weights.size() - 1; i++) {
            pq_max.push(weights[i] + weights[i + 1]);
            pq_min.push(weights[i] + weights[i + 1]);
            if (pq_max.size() > k - 1) pq_max.pop();
            if (pq_min.size() > k - 1) pq_min.pop();
            a.push_back(weights[i]);
        }
        while (!pq_max.empty()) {
            mn += pq_max.top(); pq_max.pop();
        }
        
        while (!pq_min.empty()) {
            mx += pq_min.top(); pq_min.pop();
        }
        return mx - mn;
    }
};
