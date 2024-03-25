class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> cnt(26, 0);
        int ans = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
            while (cnt[s[i] - 'a'] > 2) {
                cnt[s[j] - 'a']--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
