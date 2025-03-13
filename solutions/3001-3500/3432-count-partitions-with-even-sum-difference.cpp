class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        int l = 0, ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            int x = nums[i];
            l += x;
            s -= x;
            if ((s - l) % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};
