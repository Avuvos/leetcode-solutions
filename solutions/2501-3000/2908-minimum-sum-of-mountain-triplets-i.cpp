class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> suf(n);
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = min(suf[i + 1], nums[i]);
        }
        int pref = nums[0];
        const int inf = 1e9 + 2;
        int ans = inf;
        for (int i = 1; i + 1 < n; i++) {
            if (nums[i] > suf[i + 1] && nums[i] > pref) {
                ans = min(ans, nums[i] + pref + suf[i]);
            }
            pref = min(pref, nums[i]);
        }
        return ans < inf ? ans : -1;
    }
};
