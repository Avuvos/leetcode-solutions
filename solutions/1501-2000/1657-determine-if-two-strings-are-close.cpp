class Solution {
public:
    bool closeStrings(string word1, string word2) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        vector<int> c1(26), c2(26);
        unordered_map<int, int> mp; //map number of occ to how many times we seen that
        for (auto c: word1) c1[c - 'a']++;
        for (auto c: word2) c2[c - 'a']++;
        
        for (int i = 0; i < 26; i++) {
            if (c1[i] == 0) continue;
            if (c2[i] == 0) return false;
            mp[c1[i]]++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (c2[i] == 0) continue;
            if (mp[c2[i]] < 0) return false;
            mp[c2[i]]--;
        }
        
        for (auto [key, val]: mp) {
            if (val != 0) return false;
        }
        return true;
    }
};
