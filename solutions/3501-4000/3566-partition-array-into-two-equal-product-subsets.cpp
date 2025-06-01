class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        auto dfs = [&](auto &dfs, int idx, long long t1, long long t2) -> bool {
            if (idx >= nums.size()) {
                return t1 == 1 && t2 == 1;
            }
            bool op1 = false, op2 = false;
            if (t1 % nums[idx] == 0) {
                op1 = dfs(dfs, idx + 1, t1 / nums[idx], t2);
            }
            if (t2 % nums[idx] == 0) {
                op2 = dfs(dfs, idx + 1, t1, t2 / nums[idx]);
            }
            return op1 || op2;
        };
        return dfs(dfs, 0, target, target);
    }
};
