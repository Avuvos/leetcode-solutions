class Solution {
public:
    int minAnagramLength(string s) {
        int n = (int) s.size();
        
        auto good = [&](int len) -> bool {
            if (n % len != 0) {
                return false;
            }
            vector<int> cnt(26, 0);
            for (int i = 0; i < len; i++) {
                cnt[s[i] - 'a']++;
            }
            for (int i = len; i < n; i += len) {
                vector<int> cur(26, 0);
                for (int j = i; j < i + len; j++) {
                    cur[s[j] - 'a']++;
                }
                if (cnt != cur) {
                    return false;
                }
            }
            return true;
        };
        
        for (int i = 1; i <= n; i++) {
            if (good(i)) {
                return i;
            }
        }
        return -1;
    }
};
