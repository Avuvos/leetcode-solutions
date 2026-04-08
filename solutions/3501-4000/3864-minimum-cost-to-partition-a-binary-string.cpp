class Solution {
public:
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();
        vector<int> ps(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + (s[i] == '1');
        }

        auto dfs = [&](auto &dfs, int l, int r) -> long long {
            if (l > r) {
                return 0;
            }
            if (l == r) {
                return s[l] == '0' ? flatCost : encCost;
            }
            int len = r - l + 1;
            int ones = ps[r + 1] - ps[l];
            long long cost = ones > 0 ? 1LL * ones * len * encCost : flatCost; 
            if (len % 2 == 1) {
                return cost;
            }
            int m = (l + r) / 2;
            long long left_cost = dfs(dfs, l, m);
            long long right_cost = dfs(dfs, m + 1, r);
            long long ans = min(cost, left_cost + right_cost);
            return ans;
        };

        return dfs(dfs, 0, n - 1);
    }
};
