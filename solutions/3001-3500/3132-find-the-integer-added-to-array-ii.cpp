class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n = (int) nums1.size();
        const int inf = 1e9 + 2;
        int ans = inf;
        sort(nums2.begin(), nums2.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<int> tmp;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) {
                        tmp.push_back(nums1[k]);
                    }
                }
                sort(tmp.begin(), tmp.end());
                set<int> cands;
                for (int k = 0; k < nums2.size(); k++) {
                    cands.insert(nums2[k] - tmp[k]);
                }
                if ((int)cands.size() == 1) {
                    ans = min(ans, *cands.begin());
                }
            }
        }
        return ans;
    }
};
