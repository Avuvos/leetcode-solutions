class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> len(n);
        len[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                len[i] = 1 + len[i - 1];
            } else {
                len[i] = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            if (len[i - 1] >= k && i + k - 1 < n && len[i + k - 1] >= k) {
                return true;
            }
        }
        return false;
    }
};
