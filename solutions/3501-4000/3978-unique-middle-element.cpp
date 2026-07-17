class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size(), mid = nums[n / 2], cnt = 0;
        for (auto &x: nums) {
            if (x == mid) {
                cnt++;
            }
        }
        return cnt == 1;

    }
};
