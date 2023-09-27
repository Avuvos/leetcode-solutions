class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n = (int) s.size();
        string ans;
        
        long long len = 0;
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                int rep = s[i] - '0' - 1;
                len += 1LL * rep * len;
            } else {
                len++;
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (isdigit(s[i])) {
                int rep = s[i] - '0';
                len = len / rep;
                k = k % len;
            } else {
                if (k == len || k == 0) {
                    ans = s[i];
                    break;
                }
                len--;
            }
            
        }
        
        return ans;
    }
};

