class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = (int) nums.size();
        long long ans = 0, sum = 0;
        map<int, int> cnt;
        for (int r = 0, l = 0; r < n; r++) {
            sum += nums[r];
            cnt[nums[r]]++;
            if (r - l + 1 > k) {
                sum -= nums[l];
                if (cnt[nums[l]] == 1) {
                    cnt.erase(nums[l]);
                } else {
                    cnt[nums[l]]--;
                }
                l++;
            }
            if (r - l + 1 == k && cnt.size() >= m) {
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
