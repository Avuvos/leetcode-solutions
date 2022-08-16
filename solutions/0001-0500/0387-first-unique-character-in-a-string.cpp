class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            mp[c] = mp.count(c) ? -1 : i;
        }
        int min_index = s.size();
        for (auto const&[key, val] : mp) {
            if (val == -1) continue;
            min_index = min(min_index, val);
        }
        return min_index != s.size() ? min_index : -1;
    }
};
