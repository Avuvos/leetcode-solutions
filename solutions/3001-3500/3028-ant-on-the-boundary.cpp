class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int s = 0, ans = 0;
        for (auto &x: nums) {
            s += x;
            if (s == 0) ans++;
        }
        return ans;
    }
};
