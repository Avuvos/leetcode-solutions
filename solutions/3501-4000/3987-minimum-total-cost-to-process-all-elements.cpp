class Solution {
public:
    const int MOD = 1e9 + 7;
    const int inv2 = 500000004;
    int minimumCost(vector<int>& nums, int k) {
        long long s = accumulate(nums.begin(), nums.end(), 0LL);
        auto ok = [&](long long ops) -> bool {
            return (ops + 1) >= (s + k - 1) / k;
        };
        long long left = 0, right = 1e15 + 1, min_ops = -1;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (ok(mid)) {
                min_ops = mid % MOD;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return min_ops * (min_ops + 1) % MOD * inv2 % MOD; 
    }
};
