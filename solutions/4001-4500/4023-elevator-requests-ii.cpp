class Solution {
public:
    const long long INF = 1e18 + 2;
    long long dp[1503][1503][2];
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        auto dfs = [&](auto &dfs, int l, int r, int lside, int sz) -> long long {
            if (l == 0 && r == sz - 1) {
                return 0;
            }
            if (dp[l][r][lside] != -1) {
                return dp[l][r][lside];
            }
            long long ans = INF, len = sz - 1 - r + l, cost;
            if (l - 1 >= 0) {
                cost = len * (lside ? requests[l] - requests[l - 1] : requests[r] - requests[l - 1]);
                ans = min(ans, cost + dfs(dfs, l - 1, r, 1, sz));
            }
            if (r + 1 < sz) {
                cost = len * (lside ? requests[r + 1] - requests[l] : requests[r + 1] - requests[r]);
                ans = min(ans, cost + dfs(dfs, l, r + 1, 0, sz));
            }
            return dp[l][r][lside] = ans;
        };

        bool contains_start = any_of(requests.begin(), requests.end(), [&](int x) {
            return x == start;
        });
        if (!contains_start) {
            requests.push_back(start);
        }
        int rsz = requests.size();
        sort(requests.begin(), requests.end());
        int st_idx = lower_bound(requests.begin(), requests.end(), start) - requests.begin();
        memset(dp, -1, sizeof(dp));
        return dfs(dfs, st_idx, st_idx, 1, rsz);
    }
};
