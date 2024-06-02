class Solution {
public:
    int minimumChairs(string s) {
        int balance = 0;
        int mx = 0;
        for (auto c: s) {
            balance += (c == 'E' ? 1 : -1);
            mx = max(mx, balance);
        }
        return mx;
    }
};
