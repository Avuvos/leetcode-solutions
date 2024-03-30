class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        int n = (int) nums.size();
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        
        set<int> diffs;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                diffs.insert(abs(nums[i] - nums[j]));
            }
        }
        
        typedef long long ll;
        ll ans = 0;
        ll dp[52][52][52][2];
        for (auto &d: diffs) {
            memset(dp, -1, sizeof(dp));
            auto dfs = [&](auto dfs, int index, int len, int last, int seen) -> long long {
                if (index >= n) {
                    return len == k && seen;
                }
                if (dp[index][len][last][seen] != -1) {
                    return dp[index][len][last][seen];
                }
                ll skip = dfs(dfs, index + 1, len, last, seen);
                ll take = 0;
                if (last == n || abs(nums[index] - nums[last]) >= d) {
                    int new_seen = last < n && abs(nums[index] - nums[last]) == d;
                    take = dfs(dfs, index + 1, len + 1, index, seen | new_seen);
                }
                return dp[index][len][last][seen] = (skip + take) % MOD;
            };
            ans += d * dfs(dfs, 0, 0, n, 0);
            ans %= MOD;
        }
        return ans;
    }
};
