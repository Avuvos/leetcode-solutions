class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool all_even = true;
        int mn = 1e9 + 2;
        for (auto &x: nums1) {
            if (x % 2 == 1) {
                all_even = false;
            }
            mn = min(mn, x);
        }
        return all_even || mn % 2 == 1;
    }
};
