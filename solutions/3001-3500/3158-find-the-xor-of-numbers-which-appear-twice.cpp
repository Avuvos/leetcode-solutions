class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        map<int, int> cnt;
        int ans = 0;
        for (auto x: nums) {
            if (++cnt[x] == 2) {
                ans ^= x;
            }
        }
        return ans;
    }
};
