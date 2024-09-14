class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int n = nums.size();
        int M = 7;
        
        vector<vector<vector<bool>>> pref(n + 1, vector<vector<bool>>(k + 1, vector<bool>((1 << M) + 1, false)));
        pref[0][0][0] = true;
        for (int i = 0; i < n; ++i) {
            for (int picked = 0; picked <= k; picked++) {
                for (int mask = 0; mask < (1 << M); mask++) {
                    if (!pref[i][picked][mask]) continue;
                    pref[i + 1][picked][mask] = true;
                    if (picked < k) {
                        pref[i + 1][picked + 1][mask | nums[i]] = true;
                    }
                }
            }
        }
        
        vector<vector<vector<bool>>> suf(n + 1, vector<vector<bool>>(k + 1, vector<bool>((1 << M) + 1, false)));
        suf[n][0][0] = true;
        for (int i = n - 1; i >= 0; --i) {
            for (int picked = 0; picked <= k; picked++) {
                for (int mask = 0; mask < (1 << M); mask++) {
                    if (!suf[i + 1][picked][mask]) continue;
                    suf[i][picked][mask] = true;
                    if (picked < k) {
                        suf[i][picked + 1][mask | nums[i]] = true;
                    }
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            for (int mask1 = 0; mask1 < (1 << M); mask1++) {
                if (!pref[i][k][mask1]) continue;
                for (int mask2 = 0; mask2 < (1 << M); mask2++) {
                    if (!suf[i][k][mask2]) continue;
                    ans = max(ans, mask1 ^ mask2);
                }
            }
        }
        
        return ans;
    }
};
