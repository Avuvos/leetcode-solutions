class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return nums[i] == nums[j] ? i < j : nums[i] < nums[j];
        });
        
        int mn = n, ans = 0;
        for (auto& idx: order) {
            ans = max(ans, idx - mn);
            mn = min(mn, idx);
        }
        return ans;
    }
};
