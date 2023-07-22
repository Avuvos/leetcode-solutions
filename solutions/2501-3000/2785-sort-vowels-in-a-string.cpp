class Solution {
public:
    string sortVowels(string s) {
        int n = (int) s.size();
        vector<char> v;
        set<char> vs = {'A', 'a', 'u', 'U', 'e', 'E', 'o', 'O', 'i', 'I'};
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (vs.find(c) != vs.end()) {
                v.push_back(c);
                s[i] = '?';
            }
        }
        sort(v.begin(), v.end());
        int p = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                s[i] = v[p++];
            }
        }
        return s;
    }
};
