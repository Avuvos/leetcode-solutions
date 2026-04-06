class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        // l[i] furthest point to the left where i is dominating the OR value
        // r[i] furthest point to the right where i is dominating the OR values
        int n = nums.size();
        vector<int> l(n, -1), r(n, n), stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && (nums[stk.back()] | nums[i]) > nums[stk.back()]) {
                r[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && ((nums[stk.back()] == nums[i]) || (nums[stk.back()] | nums[i]) > nums[stk.back()])) {
                l[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += 1LL * (i - l[i]) * (r[i] - i);
        }
        return ans;

    }
};
