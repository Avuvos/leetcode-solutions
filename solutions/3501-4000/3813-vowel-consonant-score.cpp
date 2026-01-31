class Solution {
public:
    int vowelConsonantScore(string s) {
        int vow = 0, con = 0;
        set<char> vowels = {'a', 'e', 'i', 'u', 'o'};
        for (auto &c: s) {
            int val = c - 'a';
            if (val < 0 || val >= 26) {
                continue;
            }
            if (vowels.contains(c)) {
                vow++;
            } else {
                con++;
            }

        }
        return con > 0 ? vow / con : 0;
    }
};
