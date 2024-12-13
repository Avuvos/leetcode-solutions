class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ps(n + 1, 0);
        for (auto &q: queries) {
            ps[q[0]]++;
            ps[q[1] + 1]--;
        }
        for (int i = 1; i <= n; i++) {
            ps[i] += ps[i - 1];
        }
        for (int i = 0; i < n; i++) {
            nums[i] -= ps[i];
            if (nums[i] > 0) {
                return false;
            }
        }
        return true;
    }
};
