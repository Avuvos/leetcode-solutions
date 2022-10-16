class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int res = -1;
        for (auto n: nums) {
            if (n < 0) continue;
            if (find(nums.begin(), nums.end(), -n) != nums.end()) {
                res = max(res, n);
            }
        }
        return res;
    }
};
