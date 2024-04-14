class Solution {
public:
    const long long INF = 1e12;
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = (int) coins.size();
        
        auto get_lcm = [&](int mask) -> long long {
            long long ans = 1;
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    ans = lcm(ans, coins[i]);
                }
            }
            return ans;
        };
        
        auto count = [&](long long x) -> long long {
            //up to the number x, how many different numbers can be made?
            //must be inclusion exclusion principle....? D:
            //the tasks reduces to finding the size of the set (x/coins[1] unite x/coins[2] unite ...)
            long long ans = 0;
            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = get_lcm(mask);
                int bits = __builtin_popcount(mask);
                int sign = (bits & 1 ? 1 : -1);
                long long cnt = x / lcm;
                ans += sign * cnt;
            }
            return ans;
        };
        
        long long left = 0, right = INF, ans = INF;
        while (left <= right) {
            long long mid = left + (right - left)/2;
            if (count(mid) < k) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans + 1;
    }
};
