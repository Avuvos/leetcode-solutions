class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(), mx = 0;
        vector<int> ps(n + 1, 1e9 + 2);
        for (int i = n - 1; i >= 0; i--) {
            ps[i] = min(ps[i + 1], nums[i]);
        }
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            if (mx - ps[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};
