class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0, s2 = 0;
        bool hasZero1 = false, hasZero2 = false;
        for (auto x: nums1) {
            s1 += x;
            if (x == 0) {
                s1++;
                hasZero1 = true;
            }
        }
        for (auto x: nums2) {
            s2 += x;
            if (x == 0) {
                s2++;
                hasZero2 = true;
            }
        }
        if (s1 > s2 && !hasZero2) {
            return -1;
        }
        if (s2 > s1 && !hasZero1) {
            return -1;
        }
        return max(s1, s2);
    }
};
