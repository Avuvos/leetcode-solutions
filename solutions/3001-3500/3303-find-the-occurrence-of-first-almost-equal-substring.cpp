class Solution {
public:
    
    vector<int> z_function(string s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if (i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    
    int minStartingIndex(string s, string pattern) {
        int n = s.size(), m = pattern.size();
        vector<int> z = z_function(pattern + "#" + s);
        reverse(s.begin(), s.end());
        reverse(pattern.begin(), pattern.end());        
        vector<int> zr = z_function(pattern + "#" + s);
        
        for (int i = 0; i <= n - m; i++) {
            int pref = min(z[m + 1 + i], m);
            int suf = min(zr[n + 1 - i], m);
            if (pref + suf >= m - 1) {
                return i;
            }
        }
        
        return -1;
    }
};
