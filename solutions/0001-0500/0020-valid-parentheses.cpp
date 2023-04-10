class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for (auto &c: s) {
            if (c == '(' || c == '{' || c == '[') {
                if (c == '(') stk.push_back(')');
                else if (c == '{') stk.push_back('}');
                else stk.push_back(']');
            } else {
                if (stk.empty() || stk.back() != c) return false;
                stk.pop_back();
            }
        }
        return stk.empty();
    }
};
