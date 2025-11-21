class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        int y = abs(x);
        vector<int> d;
        while (y > 0) {
            d.push_back(y % 10);
            y /= 10;
        }
        int res = 0;
        for (auto &dig: d) {
            if (res > INT_MAX / 10) return 0;
            res = res * 10 + dig;
        }
        if (x < 0) res *= -1;
        return res;
    }
};
