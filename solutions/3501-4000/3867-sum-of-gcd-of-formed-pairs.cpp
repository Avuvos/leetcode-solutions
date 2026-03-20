class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        long long ans = 0;
        vector<int> pg(n);
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            pg[i] = gcd(nums[i], mx);
        } 
        sort(pg.begin(), pg.end());
        int l = 0, r = n - 1;
        while (l < r) {
            ans += gcd(pg[l++], pg[r--]);
        }
        return ans;
    }
};
