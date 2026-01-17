class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        int target = 0, res = 0;
        for (int bit = 30; bit >= 0; bit--) {
            int next_target = target | (1 << bit);
            vector<int> cost;
            for (auto &x: nums) {
                int r = next_target & (~x);
                if (r == 0) {
                    cost.push_back(0);
                    continue;
                }
                int hb = 31 - __builtin_clz(r);
                int rest = (1 << hb) - 1;
                int nx = (x & ~rest) | (1 << hb) | (next_target & rest);
                cost.push_back(nx - x);
            }
            sort(cost.begin(), cost.end());
            long long total_cost = accumulate(cost.begin(), cost.begin() + m, 0LL);
            if (total_cost <= k) {
                res = next_target;
                target = next_target;
            }
        }
        return res;
    }
};
