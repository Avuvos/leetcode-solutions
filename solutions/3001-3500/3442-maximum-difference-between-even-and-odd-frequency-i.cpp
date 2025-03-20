class Solution {
public:
    int maxDifference(string s) {
        vector<int> cnt(26, 0);
        int max_odd = 0, min_even = 10000;
        for (auto &c: s) {
            cnt[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;
            if (cnt[i] % 2 == 0) {
                min_even = min(min_even, cnt[i]);
            } else {
                max_odd = max(max_odd, cnt[i]);
            }
        }
        return max_odd - min_even;
        
        
        
        
    }
};
