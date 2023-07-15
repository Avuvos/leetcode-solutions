class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = (int) events.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1));
        sort(events.begin(), events.end());
        
        auto calc_next = [&](int index) {
            int left = index + 1, right = n - 1, ans = n;
            while (left <= right) {
                int mid = left + (right - left)/2;
                if (events[mid][0] > events[index][1]) {
                    ans = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return ans;
        };
        
        function<long long(int, int)> dfs = [&](int index, int rem) -> long long {
            if (index >= n || rem == 0) {
                return 0;
            }
            if (dp[index][rem] != -1) {
                return dp[index][rem];
            }
            long long take = events[index][2] + dfs(calc_next(index), rem - 1);
            long long skip = dfs(index + 1, rem);
            dp[index][rem] = max(take, skip);
            return dp[index][rem];
        };
        
        return dfs(0, k);
    }
};
