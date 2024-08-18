class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int o = 0, z = 0;
            for (int j = i; j < n; j++) {
                o += (s[j] == '1');
                z += (s[j] == '0');
                if (o <= k || z <= k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
