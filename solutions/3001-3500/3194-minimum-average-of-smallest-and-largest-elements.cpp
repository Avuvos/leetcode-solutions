class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double best = 300;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            best = min(best, (nums[l] + nums[r]) / 2.0);
            l++;
            r--;
        }
        return best;
    }
};
