class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int n = (int) nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i += 2) {
            ans += nums[i + 1];
        }
        return ans;
    }
};
