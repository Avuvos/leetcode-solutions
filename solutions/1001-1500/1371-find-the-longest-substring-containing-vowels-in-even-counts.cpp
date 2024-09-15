class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size(), ans = 0, mask = 0;
        unordered_map<int, int> locs;
        locs[mask] = 0;
        vector<char> vowels = {'a', 'e', 'o', 'i', 'u'};
        for (int i = 0; i < n; i++) {
            int pos = find(vowels.begin(), vowels.end(), s[i]) - vowels.begin();
            if (pos < vowels.size()) {
                mask ^= (1 << pos);
            }
            if (!locs.contains(mask)) {
                locs[mask] = i + 1;
            } else {
                ans = max(ans, i - locs[mask] + 1);
            }
        }
        return ans;
    }
};
