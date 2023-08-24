class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        int m = (int) offers.size();
        vector<int> dp(m + 1, -1);
        
        auto bin_search = [&](int index) {
            int left = index, right = m - 1, ans = m;
            while (left <= right) {
                int mid = left + (right - left)/2;
                if (offers[mid][0] > offers[index][1]) {
                    ans = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return ans;
        };
        
        function<int(int)> dfs = [&](int index) {
            if (index >= m) {
                return 0;
            }
            if (dp[index] != -1) {
                return dp[index];
            }
            return dp[index] = max(dfs(index + 1), offers[index][2] + dfs(bin_search(index)));
        };
        
        return dfs(0);
    }
};
