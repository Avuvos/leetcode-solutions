class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> cnt(26, 0);
        for (auto &c: s) {
            if (c == '?') continue;
            cnt[c - 'a']++;
        }
        
        vector<char> took;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                int mn = 1e9 + 2, index = -1;
                for (int j = 0; j < 26; j++) {
                    if (cnt[j] < mn) {
                        mn = cnt[j];
                        index = j;
                    }
                }
                char c = (char) ('a' + index);
                took.push_back(c);
                cnt[c - 'a']++;
            } 
        }
        sort(took.begin(), took.end());
        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                s[i] = took[index++];
            }
        }
        return s;
        
    }
};
