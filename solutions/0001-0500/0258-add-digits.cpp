class Solution {
public:
    int addDigits(int num) {
        
        auto add = [&](int n) {
            int res = 0;
            while (n > 0) {
                res += n % 10;
                n /= 10;
            }
            return res;
        };
        
        while (num >= 10) {
            num = add(num);
        }
        return num;
        
    }
};
