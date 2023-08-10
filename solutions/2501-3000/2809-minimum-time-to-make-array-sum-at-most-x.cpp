class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = (int) nums1.size();
        vector<pair<int, int>> a(n);
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++) {
            a[i] = make_pair(nums2[i], nums1[i]);
            s1 += nums1[i];
            s2 += nums2[i];
        }
        sort(a.begin(), a.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i][j] + a[i].first * (j + 1) + a[i].second);
            }
        }
        
        for (int t = 0; t <= n; t++) {
            if (s1 + s2*t - dp[n][t] <= x) {
                return t;
            }
        }
        
        return -1;
    }
};
