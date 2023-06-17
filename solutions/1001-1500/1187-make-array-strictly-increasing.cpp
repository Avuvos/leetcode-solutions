class Solution {
public:
    int dp[2001][2001][2];
    const int INF = 1e9;    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = (int) arr1.size(), m = (int) arr2.size();
        sort(arr2.begin(), arr2.end());
        for (int i = 0; i < n + 1; i ++)
            for (int j = 0; j < m + 1; j++)
                for (int k = 0; k < 2; k++)
                    dp[i][j][k] = -1;
                
        function<int(int, int, int)> dfs = [&](int i, int j, int first) -> int {
            if (i >= n) {
                return 0;
            }
            if (dp[i][j][first] != -1) {
                return dp[i][j][first];
            }
            int ans = INF, replace_cur = INF, dont_replace_cur = INF, prev = -1;
            if (first) {
                prev = (i > 0 ? arr1[i - 1] : -1);
            } else {
                prev = (j > 0 ? arr2[j - 1] : -1);
            }

            //can either not replace the number.
            //or replace myself with the closest one to prev, so do upper bound on prev.
            if (arr1[i] > prev) {
                dont_replace_cur = dfs(i + 1, j, 1);
            }

            int index = upper_bound(arr2.begin() + j, arr2.end(), prev) - arr2.begin();
            if (index < m) {
                replace_cur = 1 + dfs(i + 1, index + 1, 0);
            }

            ans = min(replace_cur, dont_replace_cur);
            dp[i][j][first] = ans;
            return ans;
        };
        int res = dfs(0, 0, 1);
        return res < INF ? res : -1;
    }
};
