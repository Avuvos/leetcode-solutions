class Solution {
public:
    bool scoreBalance(string s) {
        int sum = 0;
        for (auto &c: s) {
            sum = sum + (c - 'a') + 1;
        }
        int ps = 0;
        for (auto &c: s) {
            int val = (c - 'a') + 1;
            sum -= val;
            ps += val;
            if (sum == ps) {
                return true;
            }
        }
        return false;
    }
};
