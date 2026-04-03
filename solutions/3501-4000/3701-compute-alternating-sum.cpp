class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int ans = 0, sign = 1;
        for (auto &x: nums) {
            ans += sign * x;
            sign *= -1;
        }
        return ans;
    }
};
