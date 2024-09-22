class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        auto good = [&](long long t) -> bool {
            long long sum = 0;
            //worked for t seconds, if x is the worker dmg, then we need k such that
            //x * (1 + 2 + ... + k) = x * k * (k + 1) / 2 <= t.
            for (auto &x: workerTimes) {
                long long l = 0, r = 1e5, k = 1;
                while (l <= r) {
                    long long m = l + (r - l) / 2;
                    if (x * m * (m + 1) / 2 <= t) {
                        k = m;
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
                sum += k;
            }
            return sum >= mountainHeight;
        };
        
        long long left = 0, right = 1e18, ans = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (good(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
