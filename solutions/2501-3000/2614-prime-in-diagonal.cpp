class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        auto check = [&](int x) {
            if (x == 1) return false;
            for (int j = 2; j*j<=x; j++) {
                if (x % j == 0) {
                    return false;
                }
            }
            return true;
        };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i][i];
            if (check(x)) ans = max(ans, x);
            x = nums[i][n - 1 - i];
            if (check(x)) ans = max(ans, x);
        }
        return ans;
    }
};
