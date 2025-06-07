class Solution {
public:
    string resultingString(string s) {
        vector<int> stk;
        for (auto &c: s) {
            stk.push_back(c);
            while (stk.size() >= 2) {
                int m = stk.size();
                if (abs(stk[m - 1] - stk[m - 2]) == 1 || 
                   stk[m - 1] == 'a' && stk[m - 2] == 'z' ||
                   stk[m - 1] == 'z' && stk[m - 2] == 'a') {
                    stk.pop_back();
                    stk.pop_back();
                } else {
                    break;
                }
            }
        }
        string ans;
        for (auto &c: stk) ans += c;
        return ans;
    }
};
