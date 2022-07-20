class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> indicies(26);
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            indicies[c - 'a'].push_back(i);
        }
        int res = 0;
        for (auto& w: words) {
            bool found = true;
            int target = -1;
            for (auto& c: w) {
                auto iter = upper_bound(indicies[c - 'a'].begin(), indicies[c -'a'].end(), target);
                if (iter == indicies[c - 'a'].end()) {
                    found = false;
                    break;
                }
                target = *iter;
            }
            if (found) res++;
        }
        return res;
    }
};
