class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        int total = -nums.front()[0];
        int maxRight = 0;
        for (int i = 0; i < nums.size(); i++) {
            int s = nums[i][0], e = nums[i][1];
            if (s > maxRight && i > 0) {
                total -= s - maxRight - 1;
            }
            maxRight = max(maxRight, e);
        }
        total += maxRight + 1;
        return total;
    }
};
