class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        int sum = 0;
        for (int d = 1; d * d <= num; d++) {
            if (num % d == 0) {
                sum += d;
                if (d != 1 && num / d != d) {
                    sum += num / d;
                }
            }
        }
        return sum == num;
    }
};
