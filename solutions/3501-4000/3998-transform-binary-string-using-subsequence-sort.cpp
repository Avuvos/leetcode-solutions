class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size(), m = strs.size();
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                pos.push_back(i);
            }
        }
        int sz = pos.size();
        vector<bool> ans(m);
        for (int i = 0; i < m; i++) {
            string cur = strs[i];
            vector<int> cpos;
            int cz = count(cur.begin(), cur.end(), '0');
            for (int j = 0; j < n; j++) {
                if (cur[j] == '?' && cz < sz) {
                    cz++;
                    cur[j] = '0';
                }
                if (cur[j] == '0') {
                    cpos.push_back(j);
                }
            }
            if (cz != sz) {
                ans[i] = false;
                continue;
            }
            bool ok = true;
            for (int j = 0; j < sz; j++) {
                if (pos[j] < cpos[j]) {
                    ok = false;
                    break;
                }
            }
            ans[i] = ok;
        }
        return ans;
    }
};
