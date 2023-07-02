class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0;
        int m = (int) requests.size();
        for (int mask = 0; mask < (1 << m); mask++) {
            vector<int> deg(n, 0);
            int ops = 0;
            for (int i = 0; i < m; i++) {
                if ((mask >> i) & 1) {
                    deg[requests[i][0]]--;
                    deg[requests[i][1]]++;
                    ops++;
                }
            }
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (deg[i] != 0) {
                    ok = false;
                }
            }
            if (ok) {
                ans = max(ans, ops);
            }
        }
        return ans;
    }
};
