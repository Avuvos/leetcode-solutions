class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        for (auto x: nums) {
            while (x > 0) {
                ans += (x % 10) == digit;
                x /= 10;
            }
        }
        return ans;
    }
};
