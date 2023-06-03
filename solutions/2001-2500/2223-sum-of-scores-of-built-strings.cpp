class Solution {
public:
    vector<int> z_function(string &s) {
        int n = (int) s.size();
        vector<int> z(n);
        int x = 0, y = 0;
        for (int i = 1; i < n; i++) {
            z[i] = max(0, min(z[i - x], y - i + 1));
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                x = i, y = i + z[i];
                z[i]++;
            }
        }
        return z;
    }
    
    long long sumScores(string s) {
        vector<int> z = z_function(s);
        long long ans = s.size();
        for (int i = 0; i < s.size(); i++) {
            ans += z[i];
        }
        return ans;
    }
};
