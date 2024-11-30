class Solution {
public:
    int smallestNumber(int n, int t) {
        int x = n;
        while (true) {
            int d = 1, y = x;
            while (y > 0) {
                d *= (y % 10);
                y /= 10;
            }
            if (d % t == 0) {
                return x;
            }
            x++;
        }
        return -1;
    }
};
