class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n + 1;
        long long sum = 0;
        unordered_map<int, int> mp;
        for (int r = 0, l = 0; r < n; r++) {
            mp[nums[r]]++;
            if (mp[nums[r]] == 1) {
                sum += nums[r];
            }
            while (l <= r && sum >= k) {
                ans = min(ans, r - l + 1);
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    sum -= nums[l];
                }
                l++;
            }
        }

        return ans <= n ? ans : -1;
    }
};
