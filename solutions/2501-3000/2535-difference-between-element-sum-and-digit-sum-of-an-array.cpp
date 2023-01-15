class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;
        int dig = 0;
        for (auto num: nums) {
            sum += num;
            while (num > 0) {
                dig += num % 10;
                num /= 10;
            }
        }
        return abs(sum - dig);
    }
};
