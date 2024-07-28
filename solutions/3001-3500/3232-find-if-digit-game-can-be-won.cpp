class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int s1 = 0, s2 = 0;
        for (auto &x: nums) {
            if (x >= 10) {
                s2 += x;
            } else {
                s1 += x;
            }
        }
        return s1 != s2;
    }
};
