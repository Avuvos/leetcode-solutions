class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        vector<vector<bool>> sub_pal(n, vector<bool>(n, false));
        auto expand = [&](int l, int r) -> void {
            while (l >= 0 && r < n && s[l] == s[r]) {
                pal[l--][r++] = true;
            }
        };
        for (int i = 0; i < n; i++) {
            expand(i, i);
            expand(i, i + 1);
            sub_pal[i][i] = true;
            if (i + 1 < n) sub_pal[i][i + 1] = true;
        }
        int ans = 2;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                bool c1 = s[i] == s[j] && sub_pal[i + 1][j - 1];
                bool c2 = s[i] != s[j] && (pal[i + 1][j] || pal[i][j - 1]);
                if (c1 || c2) {
                    sub_pal[i][j] = true;
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans; 
    }
};
