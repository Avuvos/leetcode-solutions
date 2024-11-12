class Solution {
public:
    bool isBalanced(string num) {
        int s = 0;
        for (int i = 0; i < num.size(); i++) {
            int sign = (i % 2 == 0 ? 1 : -1);
            s += sign * (num[i] - '0');
        }
        return s == 0;
    }
};
