class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long sum = 0;
        int n = (int) nums.size();
        vector<int> ans(n, -1);
        for (int left = 0, right = 0; right < n; right++) {
            sum += nums[right];
            if (right - left + 1 > 2*k + 1) {
                sum -= nums[left];
                left++;
            }
            long long cur = (right - left + 1 == 2*k + 1 ? (sum / (2*k + 1)) : -1);
            ans[(left + right)/2] = cur;
        }
        return ans;
    }
};
