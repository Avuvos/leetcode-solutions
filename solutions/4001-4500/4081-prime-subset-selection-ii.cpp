class Solution {
public:
    const int inf = 1e9 + 2;
    vector<int> maxPrimeSubset(int n, int s) {
        vector<int> primes;
        for (int i = 2; i <= n; i++) {
            bool is_prime = true;
            for (int d = 2; d * d <= i; d++) {
                if (i % d == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime) {
                primes.push_back(i);
            }
        }
        int sz = primes.size();
        vector<bool> reachable(s + 1, false);
        reachable[0] = true;
        int mx = 0;
        for (auto &p: primes) {
            for (int i = s; i >= 1; i--) {
                if (i - p >= 0 && reachable[i - p]) {
                    reachable[i] = true;
                    mx = max(mx, i);
                }
            }
        }
        vector<int> ans;
        vector<vector<int>> dp(sz, vector<int>(mx + 1, -1));
        vector<vector<bool>> par(sz, vector<bool>(mx + 1, false));
        auto dfs = [&](auto &dfs, int i, int cur) -> int {
            if (cur == mx) {
                return 0;
            }
            if (i >= sz || cur > mx) {
                return inf;
            }
            if (dp[i][cur] != -1) {
                return dp[i][cur];
            }
            int take = 1 + dfs(dfs, i + 1, cur + primes[i]);
            int skip = dfs(dfs, i + 1, cur);
            
            par[i][cur] = take <= skip;
            return dp[i][cur] = min(take, skip);
        };
        dfs(dfs, 0, 0);
        int cur = 0;
        for (int i = 0; i < sz && cur < mx; i++) {
            if (par[i][cur]) {
                ans.push_back(primes[i]);
                cur += primes[i];
            }
        }
        return ans;
    }
};
