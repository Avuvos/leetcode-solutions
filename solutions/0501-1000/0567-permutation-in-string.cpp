class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt(26, 0);
        for (auto &c: s1) cnt[c - 'a']++;
        
        vector<int> cur_cnt(26, 0);
        for (int l = 0, r = 0; r < s2.size(); r++) {
            cur_cnt[s2[r] - 'a']++;
            while (cur_cnt[s2[r] - 'a'] > cnt[s2[r] - 'a']) {
                cur_cnt[s2[l] - 'a']--;
                l++;
            }
            if (cnt == cur_cnt) {
                return true;
            }
        }
        return false;
    }
};
