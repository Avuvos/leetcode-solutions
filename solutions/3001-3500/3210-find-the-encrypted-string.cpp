class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans;
        int n = (int) s.size();
        for (int i = 0; i < n; i++) {
            ans += s[(i + k) % n];
        }
        return ans;
    }
};
