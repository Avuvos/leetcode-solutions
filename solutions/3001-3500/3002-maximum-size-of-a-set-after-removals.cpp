class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = (int) nums1.size();
        
        map<int, int> mp1, mp2;
        set<int> all;
        for (auto &x: nums1) {
            mp1[x]++;
            all.insert(x);
        }
        for (auto &x: nums2) {
            mp2[x]++;
            all.insert(x);
        }

        int taken1 = 0, taken2 = 0;
        for (auto &x: all) {
            bool has1 = mp1.find(x) != mp1.end();
            bool has2 = mp2.find(x) != mp2.end();
            if (has1 && !has2) {
                if (taken1 < n / 2) {
                    taken1++;
                }
            } else if (has2 && !has1) {
                if (taken2 < n / 2) {
                    taken2++;
                }
            }
        }
        for (auto &x: all) {
            bool has1 = mp1.find(x) != mp1.end();
            bool has2 = mp2.find(x) != mp2.end();
            if (has1 && has2) {
                if (taken1 < n / 2) {
                    taken1++;
                } else if (taken2 < n / 2) {
                    taken2++;
                }
            }
        }

        return taken1 + taken2;
        
    }
};
