class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        const int inf = 1e9 + 2;
        int n = nums.size();
        if (n == 1) {
            return {0, 0};
        }

        auto get = [&](int p) {
            int ops = 0, mx = -inf, mn = inf;
            for (int i = 0; i < n; i++) {
                int ep = i % 2 == 0 ? p : p ^ 1;
                if (abs(nums[i]) % 2 != ep) {
                    ops++;
                    mx = max(mx, nums[i] - 1);
                    mn = min(mn, nums[i] + 1);
                } else {
                    mx = max(mx, nums[i]);
                    mn = min(mn, nums[i]);
                }
            }
            return make_pair(ops, max(1, mx - mn));
        };
        
        auto [op1, v1] = get(0);
        auto [op2, v2] = get(1);

        vector<int> ans(2);
        ans[0] = min(op1, op2);
        ans[1] = op1 < op2 ? v1 : op2 < op1 ? v2 : min(v1, v2);
        return ans;
    }
};
