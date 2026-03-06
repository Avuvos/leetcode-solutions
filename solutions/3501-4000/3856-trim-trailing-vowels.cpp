class Solution {
public:
    string trimTrailingVowels(string s) {
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};
        while (!s.empty()) {
            if (v.contains(s.back())) {
                s.pop_back();
            } else {
                break;
            }
        }
        return s;
    }
};
