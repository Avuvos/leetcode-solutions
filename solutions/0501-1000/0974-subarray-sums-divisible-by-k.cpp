class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = (int) nums.size();
        vector<int> cnt(k, 0); //cnt[i] is the number of prefixes with sum == i mod k
        int sum = 0, ans = 0;
        for (int i = 0; i < n ; i++) {
            sum += nums[i];
            sum %= k;
            if (sum < 0) sum += k;
            if (sum % k == 0) ans++;
            ans += cnt[sum];
            cnt[sum]++;
        }
        return ans;
    }
};
