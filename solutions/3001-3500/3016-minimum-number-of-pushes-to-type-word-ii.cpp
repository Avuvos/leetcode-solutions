class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26, 0);
        for (auto &c: word) cnt[c - 'a']++;
        sort(cnt.rbegin(), cnt.rend());
        int ans = 0, streak = 1, val = 1;
        for (int i = 0; i < 26 && cnt[i] > 0; i++) {
            ans += val * cnt[i];
            streak++;
            if (streak == 9) {
                streak = 1;
                val++;
            }
        }
        return ans;
    }
};
