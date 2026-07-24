class Solution {
public:
    bool validDigit(int n, int x) {
        int c = 0, lst = -1;
        while (n > 0) {
            int d = n % 10;
            c += (d == x);
            lst = d;
            n /= 10;
        }
        return c > 0 && lst != x;
    }
};
