class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = (int) nums.size();
        vector<int> ops(k + 2, 0);
        for (int i = 0; i < n / 2; i++) {
            int x = nums[i], y = nums[n - i - 1];
            if (x > y) swap(x, y); //x < y.
            int delta = y - x;
            int mx_diff = max(y, k - x);
            ops[0] += 1;
            ops[mx_diff + 1] -= 1;
            ops[mx_diff + 1] += 2;
            if (delta <= mx_diff) {
                ops[delta] -= 1;
                ops[delta + 1] += 1;
            }
        }
        for (int i = 1; i <= k; i++) {
            ops[i] += ops[i - 1];
        }
        int ans = n;
        for (int i = 0; i <= k; i++) {
            ans = min(ans, ops[i]);
        }
        
        return ans;
    }
};
