class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> cnt(26, 0);
        int mn = 1e9 + 2;
        for (auto &c: word) {
            cnt[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;
            mn = min(mn, cnt[i]);
        }
        int ans = 1e9 + 2, delta = 0;
        for (int j = 0; j < 26; j++) {
            int sum = 0;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] == 0) continue;
                if (cnt[i] - mn <= k) continue;
                sum += (cnt[i] - (mn + k));
            }
            ans = min(ans, sum + delta);
            for (int i = 0; i < 26; i++) {
                if (cnt[i] == 0) continue;
                if (cnt[i] == mn) {
                    cnt[i] = 0;
                    delta += mn;
                    break;
                }
            }
            mn = 1e9 + 2;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] == 0) continue;
                mn = min(mn, cnt[i]);
            }
            if (mn >= 1e9) break;
        }
        
        return ans;
    }
};

