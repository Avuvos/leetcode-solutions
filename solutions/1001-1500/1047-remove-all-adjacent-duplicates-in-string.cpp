class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if  (!stk.empty() && stk.top() == s[i]) {
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }
        string r = "";
        while (!stk.empty()) {
            r += stk.top();
            stk.pop();
        }
        reverse(r.begin(), r.end());
        return r;
    }
};
