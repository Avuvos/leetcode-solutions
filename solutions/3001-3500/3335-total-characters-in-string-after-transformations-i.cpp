class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> cnt(26, 0);
        for (auto &c: s) cnt[c - 'a']++;
        
        while (t--) {
            long long z = cnt[25];
            for (int i = 24; i >= 0; i--) {
                cnt[i + 1] = cnt[i]; 
            }
            cnt[0] = z;
            cnt[1] = (cnt[1] + z) % MOD;
        }
        
        long long ans = 0;
        for (auto &x: cnt) {
            ans = (ans + x) % MOD;
        }
        return ans;
    }
};
