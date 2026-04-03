class Solution {
public:
    string removeSubstring(string s, int k) {
        int n = s.size();
        vector<pair<char, int>> stk;
        for (auto &c: s) {
            int cnt = 1;
            if (!stk.empty() && stk.back().first == c) {
                cnt = stk.back().second + 1;
            }
            stk.push_back({c, cnt});
            
            // pop k-balanced sequences
            if (stk.size() >= 2 * k && stk.back().first == ')' && stk.back().second == k) {
                int last_open_idx = stk.size() - k - 1;
                if (stk[last_open_idx].first == '(' && stk[last_open_idx].second >= k) {
                    for (int i = 0; i < 2 * k; ++i) {
                        stk.pop_back();
                    }
                }
            }

        }
        string ans;
        for (auto &[c, _]: stk) {
            ans.push_back(c);
        }
        return ans;
    }
};
