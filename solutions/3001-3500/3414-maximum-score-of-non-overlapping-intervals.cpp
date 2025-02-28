class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<array<int, 4>> a(n);
        
        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
        sort(a.begin(), a.end());
        
        
        auto calc_next_index = [&](int index) -> int {
            int l = index + 1, r = n - 1, ans = n;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (a[m][0] > a[index][1]) {
                    ans = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            return ans;
        };
        
        
        vector<vector<pair<long long, vector<int>>>> dp(n, vector<pair<long long, vector<int>>>(5, {-1, {}}));
        
        auto dfs = [&](auto &dfs, int index, int cnt) -> pair<long long, vector<int>> {
            if (index >= n || cnt >= 4) {
                return {0LL, {}};
            }
            
            if (dp[index][cnt].first != -1) {
                return dp[index][cnt];
            }
            long long best = 0;
            vector<int> ans_vec = {};
            
            auto [skip_val, skip_vec] = dfs(dfs, index + 1, cnt);
            best = skip_val;
            ans_vec = skip_vec;
            sort(ans_vec.begin(), ans_vec.end());
            
            int next_index = calc_next_index(index);
            auto [take_val, take_vec] = dfs(dfs, next_index, cnt + 1);
            take_val += a[index][2];
            take_vec.push_back(a[index][3]);
            sort(take_vec.begin(), take_vec.end());
            
            if (take_val > best || (take_val == best && take_vec < ans_vec)) {
                best = take_val;
                ans_vec = take_vec;
            }
            return dp[index][cnt] = {best, ans_vec};
        };
        
        return dfs(dfs, 0, 0).second;
    }
};
