class Solution {
public:
    string smallestString(string s) {
        int n = (int) s.size();
        bool start = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' && start) break;
            if (s[i] == 'a') continue;
            start = true;
            s[i] = s[i] - 1;
        }
        if (!start) {
            s[n - 1] = 'z';
        }
        return s;
    }
};
