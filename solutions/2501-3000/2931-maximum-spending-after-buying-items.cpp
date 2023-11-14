class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long ans = 0;
        int m = (int) values.size(), n = (int) values[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        for (int i = 0; i < m; i++) {
            pq.push(make_tuple(values[i][n - 1], i, n - 1));
        }
        long long d = 1;
        while (!pq.empty()) {
            auto [v, i, j] = pq.top(); pq.pop();
            ans += d * v;
            if (j - 1 >= 0) {
                pq.push(make_tuple(values[i][j - 1], i, j - 1));
            }
            d++;
        }
        return ans;
    }
};
