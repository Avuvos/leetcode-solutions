typedef long long ll;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        ll ans = 0;
        int n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            //i want all nums[j] st nums[j] >= lower - cur and nums[j] <= upper - cur
            auto it = lower_bound(nums.begin() + i + 1, nums.end(), lower - cur);
            int l = i + 1, r = n - 1;
            int idx2 = -1;
            while (l <= r) {
                int m = l + (r - l)/2;
                if (nums[m] <= upper - cur) {
                    idx2 = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            if (it != nums.end()) {
                int idx = it - nums.begin();
                if (idx > idx2) continue;
                ans += idx2 - idx + 1;
            }
        }
        return ans;
        
    }
};
