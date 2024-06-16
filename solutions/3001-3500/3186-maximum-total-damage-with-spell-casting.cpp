class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> cnt;
        for (auto &p: power) {
            cnt[p]++;
        }
        sort(power.begin(), power.end());
        power.resize(unique(power.begin(), power.end()) - power.begin());
        int n = (int) power.size();
        vector<long long> dp(n, -1);
        
        auto calc_next_index = [&](int index) -> int {
            if (index + 1 < n && power[index + 1] - power[index] > 2) {
                return index + 1;
            }
            if (index + 2 < n && power[index + 2] - power[index] > 2) {
                return index + 2;
            }
            return index + 3;
        };
        
        auto dfs = [&](auto &dfs, int index) -> long long {
            if (index >= n) {
                return 0;
            }
            if (dp[index] != -1) {
                return dp[index];
            }
            long long skip = dfs(dfs, index + 1);
            long long take = 1LL * cnt[power[index]] * power[index] + dfs(dfs, calc_next_index(index));
            return dp[index] = max(skip, take);
        };
        return dfs(dfs, 0);
    }
};
