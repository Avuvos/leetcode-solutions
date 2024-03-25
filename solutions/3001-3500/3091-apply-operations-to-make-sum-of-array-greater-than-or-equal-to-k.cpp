class Solution {
public:
    int minOperations(int k) {
        int ops = 0;
        int sum = 1;
        int ans = 1e9;
        while (sum <= k) {
            ans = min(ans, ops + (k - sum + sum - 1)/sum);
            sum++;
            ops++;
        }
        return ans;
    }
};
