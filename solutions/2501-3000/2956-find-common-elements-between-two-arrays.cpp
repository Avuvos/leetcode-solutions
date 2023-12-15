class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(2, 0);
        for (int i = 0; i < nums1.size(); i++) {
            if (count(nums2.begin(), nums2.end(), nums1[i]) > 0) {
                ans[0]++;
            }
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (count(nums1.begin(), nums1.end(), nums2[i]) > 0) {
                ans[1]++;
            }
        }
        return ans;
    }
};
