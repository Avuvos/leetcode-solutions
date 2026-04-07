class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        auto good = [&](int k) -> bool {
            int prev_max = -1;
            for (int i = 0; i < n; i += k) {
                vector<int> cur(nums.begin() + i, nums.begin() + i + k);
                
                // at most one flip to sort the array
                int flips = 0;
                for (int j = 0; j < k; j++) {
                    if (cur[j] > cur[(j + 1) % k]) {
                        flips++;
                    }
                }
                if (flips > 1) {
                    return false;
                }

                // check & update prev max
                int mn = *min_element(cur.begin(), cur.end());
                if (mn < prev_max) {
                    return false;
                }
                prev_max = *max_element(cur.begin(), cur.end());
            }
            return true;
        };

        for (int k = 1; k * k <= n; k++) {
            if (n % k == 0) {
                if (good(k)) {
                    ans += k;
                }
                if (n / k != k && good(n / k)) {
                    ans += (n / k);
                }
            }
        }
        return ans;
    }
};
