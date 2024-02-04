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
    
    int minimumTimeToInitialState(string word, int k) {
        vector<int> z = z_function(word);
        int n = (int) word.size();
        int ans = (n + k - 1) / k;
        for (int i = 0; i < n; i++) {
            if (z[i] + i == n && i % k == 0) {
                ans = min(ans, i / k);
            }
        }
        return ans;
    }
};
