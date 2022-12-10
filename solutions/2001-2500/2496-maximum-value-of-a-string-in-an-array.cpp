class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int res = 0;
        for (auto s: strs) {
            bool non_digit = false;
            for (auto c: s) {
                if ('0' <= c && c <= '9') {
                    continue;
                }
                non_digit = true;
            }
            if (non_digit) {
                res = max(res, (int)s.size());
            } else {
                res = max(res, stoi(s));
            }
        }
        return res;
    }
};
