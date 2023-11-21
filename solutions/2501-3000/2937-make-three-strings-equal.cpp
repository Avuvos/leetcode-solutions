class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        vector<string> a = {s1, s2, s3};
        sort(a.begin(), a.end(), [&](const string &s, const string &t) {
           return s.size() < t.size(); 
        });
        if (s1[0] != s2[0] || s2[0] != s3[0] || s1[0] != s3[0]) {
            return -1;
        }
        int ans = a[0].size() + a[1].size() + a[2].size() - 3;
        int i = 1;
        while (i < a[0].size()) {
            if (a[0][i] != a[1][i] || a[0][i] != a[2][i]) {
                return ans;
            }
            i++;
            ans -= 3;
        }
        return ans;
    }
};
