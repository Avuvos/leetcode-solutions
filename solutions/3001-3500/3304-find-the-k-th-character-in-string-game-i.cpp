class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while (s.size() < k) {
            string t;
            for (auto &c: s) {
                char nc = (c == 'z' ? 'a' : c + 1);
                t += nc;
            }
            s += t;
        }
        return s[k - 1];
    }
};
