class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        for (auto& a: nums) {
            x ^= a;
        }
        int ans = 0;
        for (int bit = 0; bit < 30; bit++) {
            int kbit = (k >> bit) & 1;
            int xbit = (x >> bit) & 1;
            if (xbit != kbit) {
                ans++;
            }
        }
        return ans;
    }
};
