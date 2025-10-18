class Solution {
public:

    bool check(vector<int> &freq) {
        int cnt = -1;
        for (int k = 0; k < 26; k++) {
            if (freq[k] == 0) continue;
            if (cnt == -1) {
                cnt = freq[k];
            } else if (cnt != freq[k]) {
                return false;
            }
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                if (check(freq)) {
                    ans = max(ans, j - i + 1);
                }
            }
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']--;
            }
            freq.assign(26, 0);
        }
        return ans;
    }
};
