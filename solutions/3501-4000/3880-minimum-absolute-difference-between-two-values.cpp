class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int last_one = -1, last_two = -1, ans = 1e9;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                last_one = i;
                if (last_two != -1) {
                    ans = min(ans, i - last_two);
                }
            }
            if (nums[i] == 2) {
                last_two = i;
                if (last_one != -1) {
                    ans = min(ans, i - last_one);
                }
            }
        }
        return ans < 1e9 ? ans : -1;
    }
};
