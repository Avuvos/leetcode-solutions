class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = (int) nums.size();
        int m = (int) to_string(nums[0]).size();
        vector<vector<int>> cnt(m, vector<int>(10, 0));
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int j = 0;
            while (x > 0) {
                cnt[j][x % 10] += 1;
                j++;
                x /= 10;
            }
        }
        
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int j = 0;
            while (x > 0) {
                int r = x % 10;
                ans += (n - cnt[j][r]);
                j++;
                x /= 10;
            }
        }
        return ans / 2;

    }
};
