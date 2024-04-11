class Solution {
public:
    string getSmallestString(string s, int k) {
        string t;
        for (int i = 0; i < s.size(); i++) {
            bool ok = false;
            int val = s[i] - 'a';
            for (int j = 0; j < 26; j++) {
                int cost = min(26 - val + j, abs(val - j));
                if (cost <= k) {
                    k -= cost;
                    t += (char)('a' + j);
                    ok = true;
                    break;
                }
            }
            if (!ok) t += s[i];
        }
        return t;
    }
};
