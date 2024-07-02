class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> cnt1(1001, 0), cnt2(1001, 0);
        for (auto &x: nums1) cnt1[x]++;
        for (auto &x: nums2) cnt2[x]++;
        vector<int> ans;
        for (int i = 0; i <= 1000; i++) {
            int mn = min(cnt1[i], cnt2[i]);
            for (int j = 0; j < mn; j++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
