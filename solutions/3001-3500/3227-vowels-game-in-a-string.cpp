class Solution {
public:
    bool doesAliceWin(string s) {
        int vowels = 0;
        for (auto& c: s) {
            if (c == 'a' || c == 'u' || c == 'e' || c == 'i' || c == 'o') {
                vowels++;
            }
        }
        return vowels > 0;
    }
};
