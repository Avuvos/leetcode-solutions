class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int y = x, s = 0;
        while (y > 0) {
            s += (y % 10);
            y /= 10;
        }
        return x % s == 0 ? s : -1;
    }
};
