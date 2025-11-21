class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        auto self_divide = [&](int x) -> bool {
            int y = x;
            while (x > 0) {
                int r = x % 10;
                if (r == 0 || y % r != 0) return false;
                x /= 10;
            }
            return true;
        };
        vector<int> res;
        for (int x = left; x <= right; x++) {
            if (self_divide(x)) {
                res.push_back(x);
            }
        }
        return res;
    }
};
