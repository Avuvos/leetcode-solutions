class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for (auto &c: s) {
            int num = (c - 'a' + 1);
            sum += (num % 10);
            sum += (num / 10);
        }
        
        auto work = [&](int x) -> int {
            int res = 0;
            while (x > 0) {
                res += x % 10;
                x /= 10;
            }
            return res;
        };
        k--;
        while (k-- && sum >= 10) {
            sum = work(sum);
        }
        
        return sum;
    }
};
