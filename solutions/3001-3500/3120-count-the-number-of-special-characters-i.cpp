class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);
        for (auto &c: word) {
            if (islower(c)) {
                cnt1[c - 'a']++;
            } else {
                cnt2[c - 'A']++;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += (cnt1[i] > 0 && cnt2[i] > 0);
        }
        return ans;
    }
};
