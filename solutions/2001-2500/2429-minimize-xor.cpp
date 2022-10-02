class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ones = 0;
        while (num2 > 0) {
            ones += num2 % 2;
            num2 = num2 / 2;
        }
        long long res = 0;
        vector<bool> used(30, false);
        for (int bit = 30; bit >= 0; bit--) {
            if (((num1 >> bit) & 1) && ones > 0) {
                used[bit] = true;
                ones--;
                res += pow(2, bit);
            }
        }
        int index = 0;
        while (ones > 0) {
            while (used[index]) index++;
            used[index] = true;
            res += pow(2, index);
            ones--;
        }
        return res;
    }
};
