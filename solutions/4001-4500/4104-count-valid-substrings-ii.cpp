class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> pos(3);
        for (int i = 0; i < n; i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        long long invalid = 0;
        for (int i = 0; i < n; i++) {
            auto ita = lower_bound(pos[0].begin(), pos[0].end(), i);
            if (ita == pos[0].end()) continue;
            auto itb = lower_bound(pos[1].begin(), pos[1].end(), *ita);
            if (itb == pos[1].end()) continue;
            auto itc = lower_bound(pos[2].begin(), pos[2].end(), *itb);
            if (itc == pos[2].end()) continue;
            invalid += (n - *itc);
        }
        return 1LL * n * (n + 1) / 2 - invalid;
    }
};
