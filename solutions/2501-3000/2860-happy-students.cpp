class Solution {
public:
    int countWays(vector<int>& nums) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        
        for (int k = 0; k <= n; k++) {
            int idx = upper_bound(nums.begin(), nums.end(), k) - nums.begin() - 1;
            if (idx >= 0 && nums[idx] == k) continue;
            if (idx + 1 == k) ans++;
        }
        return ans;
    }
};
