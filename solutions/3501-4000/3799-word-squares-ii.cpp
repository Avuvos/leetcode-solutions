class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();


        auto check = [&](string& top, string& left, string& right, string& bot) -> bool {
            return top[0] == left[0] && top[3] == right[0] && bot[0] == left[3] && bot[3] == right[3];
        };

        vector<vector<string>> ans;
        vector<string> p(4);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (words[i] == words[j]) continue;
                for (int k = j + 1; k < n; k++) {
                    if (words[k] == words[i] || words[k] == words[j]) continue;
                    for (int l = k + 1; l < n; l++) {
                        if (words[l] == words[k] || words[l] == words[j] || words[l] == words[i]) continue;
                        p[0] = words[i];
                        p[1] = words[j];
                        p[2] = words[k];
                        p[3] = words[l];
                        sort(p.begin(), p.end());
                        do {
                            if (check(p[0], p[1], p[2], p[3])) {
                                ans.push_back(p);
                            }
                        } while (next_permutation(p.begin(), p.end()));
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
