class Solution {
public:
    string mergeCharacters(string s, int k) {
        vector<int> cur;
        for (auto &c: s) cur.push_back(c - 'a');

        while (true) {
            vector<int> next_cur;
            int n = cur.size();
            vector<vector<int>> pos(26);
            for (int i = 0; i < n; i++) {
                pos[cur[i]].push_back(i);
            }
            int to_remove = n, lowest_first = n;
            for (int i = 0; i < 26; i++) {
                auto &p = pos[i];
                if (p.size() == 0) continue;
                int prev = p[0];
                for (int j = 1; j < p.size(); j++) {
                    if (p[j] - prev <= k) {
                        if (prev < lowest_first) {
                            lowest_first = prev;
                            to_remove = p[j];
                        }
                        break;
                    } else {
                        prev = p[j];
                    }
                }
            }
            if (to_remove == n) {
                break;
            }
            for (int i = 0; i < n; i++) {
                if (to_remove == i) {
                    continue;
                }
                next_cur.push_back(cur[i]);
            }
            cur = next_cur;
        }
        string ans;
        for (auto &i: cur) {
            ans.push_back(char('a' + i));
        }
        return ans;
    }
};
