class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        int tmp = num;
        while (num > 0) {
            int rem = num % 10;
            res += (tmp % rem == 0);
            num /= 10;
        }
        return res;
    }
};
