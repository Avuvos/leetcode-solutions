class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        const long long INF = 1e17;
        vector<long long> ps(k, INF);
        ps[k - 1] = 0;
        long long sum = 0, ans = -INF;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ans = max(ans, sum - ps[i % k]);
            ps[i % k] = min(ps[i % k], sum);
        }
        return ans;
    }
};
