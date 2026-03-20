class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), ans = 0;
        unordered_map<int, int> mp, mp1, mp2;
        for (auto &x: nums1) {
            mp[x]++;
            mp1[x]++;
        } 
        for (auto &x: nums2) {
            mp[x]++;
            mp2[x]++;
        }
        for (auto [_, v]: mp) {
            if (v & 1) {
                return -1;
            }
        }

        int e1 = 0, e2 = 0;
        for (auto &[k, v]: mp1) {
            int v2 = mp2[k];
            if (v > v2) {
                e1 += (v - v2);
            } else {
                e2 += (v2 - v);
            }
            mp2.erase(k);
        }
        for (auto &[k, v]: mp2) {
            int v1 = mp1[k];
            if (v > v1) {
                e2 += (v - v1);
            } else {
                e1 += (v1 - v);
            }
            mp1.erase(k);
        }
        return max(e1, e2) / 2;
    }
};
