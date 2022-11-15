class Solution {
public:
    
    void extend_palindrome(int l, int r, string s, vector<vector<bool>>& isPal) {
        while (l >= 0 && r < s.size()) {
            if (s[l] != s[r]) break;
            isPal[r][l] = true;
            l--;
            r++;
        }
    }
    
    
    int maxPalindromes(string s, int k) {
        int n = s.size();
        //dp[i] prefix i dp[m]
        vector<int> dp(n + 1, 0);
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            isPal[i][i] = true;
            extend_palindrome(i, i, s, isPal);
            extend_palindrome(i, i + 1, s, isPal);
            /*
            int l = i, r = i;
            while (l >= 0 && r < n) {
                if (s[l] == s[r]) {
                    isPal[r][l] = true;
                    l--;
                    r++;
                } else {
                    break;
                }
            }
            l = i, r = i + 1;
            while (l >= 0 && r < n) {
                if (s[l] == s[r]) {
                    isPal[r][l] = true;
                    l--;
                    r++;
                } else {
                    break;
                }
            }
            */
        }
        for (int i = k - 1; i < n; i++) {
            if (i > 0) dp[i] = max(dp[i], dp[i - 1]);
            //cout << "i =" << i << endl;
            for (int j = 0; j <= i - k + 1; j++) {
                if (isPal[i][j] && j == 0) {
                    dp[i] = max(dp[i], 1);
                } else if (isPal[i][j]) {
                    dp[i] = max(dp[i], 1 + dp[j - 1]);
                }
            }
        }
        return dp[n - 1];        
    }
};
