class Solution {
public:
    int dp[1002][1002][2];
    int minLength(string s, int numOps) {
        //dp[i][l][p] = min num of ops required to get a max substr of length l.
        int n = s.size();
        const int inf = 1e9 + 2;
        
        auto possible = [&](int t) -> bool {
            memset(dp, -1, sizeof(dp));
            auto dfs = [&](auto &dfs, int i, int p, int l, int t) -> int {
                if (l > t) {
                    return inf;
                }
                if (i >= n) {
                    return 0;
                }
                if (dp[i][l][p] != -1) {
                    return dp[i][l][p];
                }
                int best = inf;
                int cur = s[i] - '0';
                int f = cur ^ 1;

                //dont flip
                if (cur == p) { 
                    int dl = (i == 0 ? 0 : 1);
                    best = min(best, dfs(dfs, i + 1, cur, l + dl, t));
                } else {
                    best = min(best, dfs(dfs, i + 1, cur, 1, t));
                }

                //flip
                if (f == p) {
                    int dl = (i == 0 ? 0 : 1);
                    best = min(best, 1 + dfs(dfs, i + 1, f, l + dl, t));
                } else {
                    best = min(best, 1 + dfs(dfs, i + 1, f, 1, t));
                }

                return dp[i][l][p] = best;
            };
            int total_ops = dfs(dfs, 0, 0, 1, t);
            return total_ops <= numOps;
        };
        

        int left = 0, right = n, ans = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (possible(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
        
    }
};
