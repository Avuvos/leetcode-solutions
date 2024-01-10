class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = (int) s.size();
        
        map<tuple<int, int, int>, int> dp;
        auto dfs = [&](auto dfs, int i, int mask, int can) -> int {
            if (i >= n) {
                return 1;
            }
            if (dp.find(make_tuple(i, mask, can)) != dp.end()) {
                return dp[make_tuple(i, mask, can)];
            }
            int c = (1 << (s[i] - 'a'));
            int next_mask = mask | c;
            int ans = 0;
            if (__builtin_popcount(next_mask) > k) {
                ans = 1 + dfs(dfs, i + 1, c ,can);
            }
            else {
                ans = dfs(dfs, i + 1, next_mask, can);
            } 
            if (can) {
                for (int t = 0; t < 26; t++) {
                    if (t == (s[i] - 'a')) continue;
                    next_mask = mask | (1 << t);
                    if (__builtin_popcount(next_mask) > k) {
                        ans = max(ans, 1 + dfs(dfs, i + 1, (1 << t), 0));
                    } else {
                        ans = max(ans, dfs(dfs, i + 1, next_mask, 0));
                    }
                }
            }
            return dp[make_tuple(i, mask, can)] = ans;
        };
        return dfs(dfs, 0, 0, 1);
    }
};
