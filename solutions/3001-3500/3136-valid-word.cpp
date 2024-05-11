class Solution {
public:
    bool isValid(string word) {
        bool v = false, c = false, good = true;
        set<char> vowels = {'a', 'i', 'o', 'u', 'e', 'A', 'I', 'O', 'U', 'E'};
        for (auto &chr: word) {
            if (vowels.find(chr) != vowels.end()) {
                v = true;
            } else if (chr > '9'|| chr < '0') {
                c = true;
            }
            good &= (chr != '@' && chr != '#' && chr != '$');
        }
        return v && c && good && word.size() >= 3;
    }
};
