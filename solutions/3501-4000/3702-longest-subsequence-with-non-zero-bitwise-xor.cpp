class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // the whole subseq is non zero -> there is at least one non zero bit
        // lets iterate over that bit
        int n = nums.size(), ans = 0;
        for (int b = 0; b < 30; b++) {
            int has = 0, rest = 0;
            for (auto &x: nums) {
                if ((x >> b) & 1) {
                    has++;
                } else {
                    rest++;
                }
            }
            if (has > 0) {
                if (has % 2 == 0) has--;
                ans = max(ans, rest + has);
            }
        }
        return ans;
    }
};
