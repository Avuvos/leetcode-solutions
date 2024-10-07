class Solution {
public:
    int minLength(string s) {
        vector<char> stk;
        for (auto &c: s) {
            if (!stk.empty() && ((stk.back() == 'A' && c == 'B') || (stk.back() == 'C' && c == 'D'))) {
                stk.pop_back();
            } else {
                stk.push_back(c);
            }
        }
        return stk.size();
    }
};
