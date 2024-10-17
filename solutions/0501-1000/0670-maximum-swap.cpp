class Solution {
public:
    int maximumSwap(int num) {
        int ans = num;
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        auto calc = [&]() -> int {
            int x = 0;
            for (int i = 0; i < digits.size(); i++) {
                x *= 10;
                x += digits[i];
            }
            return x;
        };
        
        for (int i = 0; i < digits.size(); i++) {
            for (int j = i + 1; j < digits.size(); j++) {
                swap(digits[i], digits[j]);
                ans = max(ans, calc());
                swap(digits[i], digits[j]);
            }
        }
        return ans;
    }
};
