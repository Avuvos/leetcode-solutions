class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<bool> seen(k + 1, false);
        int ans = 0;
        int cnt = 0;
        for (int i = nums.size() - 1; i >= 0 && cnt < k; i--) {
            if (nums[i] <= k && !seen[nums[i]]) {
                seen[nums[i]] = true;
                cnt++;
            }
            ans++;
        }
        return ans;
    }
};
