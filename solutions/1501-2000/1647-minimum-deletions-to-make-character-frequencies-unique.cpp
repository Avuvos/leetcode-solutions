class Solution {
public:
    int minDeletions(string s) {
        int n = (int) s.size();
        vector<int> freq(26, 0);
        for (auto &c: s) freq[c - 'a']++;
        vector<int> cnt(n + 1, 0);
        for(int i = 0; i < 26; i++) {
            cnt[freq[i]]++;
        }
        
        int ans = 0;
        for (int i = n; i > 0; i--) {
            int d = max(0, cnt[i] - 1);
            cnt[i - 1] += d;
            ans += d;
        }
        return ans;
        
    }
};
