class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<char> even1, odd1, even2, odd2;
        for (int i = 0; i < s1.size(); i++) {
            if (i & 1) {
                odd1.push_back(s1[i]);
                odd2.push_back(s2[i]);
            } else {
                even1.push_back(s1[i]);
                even2.push_back(s2[i]);
            }
        }
        sort(odd1.begin(), odd1.end());
        sort(odd2.begin(), odd2.end());
        sort(even1.begin(), even1.end());
        sort(even2.begin(), even2.end());
        for (int i = 0; i < even1.size(); i++) {
            if (even1[i] != even2[i]) {
                return false;
            }
        }
        for (int i = 0; i < odd1.size(); i++) {
            if (odd1[i] != odd2[i]) {
                return false;
            }
        }
        return true;
    }
};
