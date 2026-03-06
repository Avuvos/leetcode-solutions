class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int n = nums.size(), good = 0;
        long long ans = 0;
        unordered_map<int, int> mp_d, mp_v; //mp distinct, mp values
        for (int l = 0, l2 = 0, r = 0; r < n; r++) {
            mp_d[nums[r]]++;
            while (l <= r && mp_d.size() > k) {
                if (--mp_d[nums[l]] == 0) {
                    mp_d.erase(nums[l]);
                }
                l++;
            }
            if (++mp_v[nums[r]] == m) {
                good++;
            }
            while (good >= k) {
                if (--mp_v[nums[l2]] == m - 1) {
                    good--;
                }
                l2++;
            }
            if (l < l2) {
                ans += (l2 - l);
            }
        }
        return ans;
    }
};
