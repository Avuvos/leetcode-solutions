class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        vector<int> cnt(24, 0);
        for (auto &h: hours) {
            h %= 24;
            ans += cnt[(24 - h) % 24];
            cnt[h]++;
        }
        return ans;
    }
};
