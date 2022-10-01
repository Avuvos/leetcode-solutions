class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int n = nums1.size();
        int m = nums2.size();

        for (auto a: nums1) {
            if (m % 2 == 0) continue;
            res ^= a;
        }
        for (auto a: nums2) {
            if (n % 2 == 0) continue;
            res ^= a;
        }
        return res;
    }
};
