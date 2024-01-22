class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26, 0);
        for (auto c: word) cnt[c - 'a']++;
        sort(cnt.rbegin(), cnt.rend());
        int cost = 1;
        int cur = 1;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) break;
            ans += cost * cnt[i];
            cur++;
            if (cur == 9) {
                cur = 1;
                cost++;
            }
        }
        return ans;
    }
};
