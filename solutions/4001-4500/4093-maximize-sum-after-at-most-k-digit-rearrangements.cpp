class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(n);
        for (int i = 0; i < n; i++) {
            string s = to_string(nums[i]);
            sort(s.rbegin(), s.rend());
            f[i] = stoi(s);
        }
        vector<pair<int, int>> d(n);
        for (int i = 0; i < n; i++) {
            d[i] = {f[i] - nums[i], i};
        }
        sort(d.rbegin(), d.rend());
        long long ans = 0;
        for (auto [_, i]: d) {
            ans += (k > 0 ? f[i] : nums[i]);
            k--;
        }
        return ans;
    }
};
