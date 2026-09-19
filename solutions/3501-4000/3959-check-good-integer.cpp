class Solution {
public:
    bool checkGoodInteger(int n) {
        int s = 0;
        while (n > 0) {
            int d = n % 10;
            s += d * (d - 1);
            n /= 10;
        }
        return s >= 50;
    }
};
