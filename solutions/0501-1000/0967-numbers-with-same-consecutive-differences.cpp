class Solution {
public:
    vector<int> result;
    void rec(int n, int k, int current_number) {
        if (n == 0) {
            result.push_back(current_number);
            return;
        }
        int prev_digit = current_number % 10;
        if (prev_digit + k < 10) {
            rec(n - 1, k, current_number * 10 + prev_digit + k);
        }
        if (prev_digit - k >= 0 and k > 0) {
            rec(n - 1, k, current_number * 10 + prev_digit - k);
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        result.clear();
        for (int digit = 1; digit <= 9; ++digit) {
            rec(n - 1, k, digit);
        }
        return result;
    }
};
