class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 0; i < s.size() - 1; i++) {
            int x = s[i] - '0';
            int y = s[i + 1] - '0';
            if (x <= y || x % 2 != y % 2) continue;
            swap(s[i], s[i + 1]);
            break;
        }
        return s;
    }
};
