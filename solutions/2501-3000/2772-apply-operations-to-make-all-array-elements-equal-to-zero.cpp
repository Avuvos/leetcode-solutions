class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = (int) nums.size();
        vector<int> ps(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0) ps[i] += ps[i - 1];
            nums[i] -= ps[i];
            if (nums[i] == 0) continue;
            if (nums[i] < 0 || i + k > n) return false;
            ps[i] += nums[i];
            ps[i + k] -= nums[i];
        }
        return true;
    }
};
