class Solution {
public:
    int numSteps(string s) {
        int n = (int) s.size();
        int ans = 0, carry = 0;
        for (int i = n - 1; i > 0; i--) {
            if (s[i] == '0' && carry == 0) {
                ans++;
                carry = 0;
            } else if (s[i] == '0' && carry == 1) {
                ans += 2;
                carry = 1;
            } else if (s[i] == '1' && carry == 0) {
                ans += 2;
                carry = 1;
            } else if (s[i] == '1' && carry == 1) {
                ans++;
                carry = 1;
            } else {
                assert(false);
            }
        }
        if (carry) {
            ans++;
        }
        
        return ans;
    }
};
