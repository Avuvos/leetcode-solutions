class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m = (int) queries.size(), n = (int) nums.size();
        vector<long long> ans(m);
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        vector<bool> marked(n, false);
        for (int i = 0; i < m; i++) {
            int index = queries[i][0];
            int k = queries[i][1];
            if (!marked[index]) {
                sum -= nums[index];
                marked[index] = true;
            }
            int iter = 0;
            while (!pq.empty() && iter < k) {
                auto [val, cur_idx] = pq.top(); pq.pop();
                if (marked[cur_idx]) continue;
                marked[cur_idx] = true;
                sum -= val;
                iter++;
            }
            ans[i] = sum;
        }
        return ans;
    }
};
