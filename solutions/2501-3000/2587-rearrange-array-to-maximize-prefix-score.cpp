class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        long long s = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            if (s > 0) ans++;
        }
        return ans;
    }
};
