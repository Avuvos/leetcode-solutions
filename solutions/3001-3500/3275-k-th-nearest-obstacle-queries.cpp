class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n = queries.size();
        vector<int> ans(n, -1);
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int x = queries[i][0], y = queries[i][1];
            pq.push(abs(x) + abs(y));
            while (pq.size() > k) {
                pq.pop();
            }
            if (pq.size() == k) {
                ans[i] = pq.top();
            }
        }
        return ans;
    }
};
