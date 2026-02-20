class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = 1LL * nums[i] * nums[i];
        }
        sort(a.begin(), a.end());
        int l = 0, r = n - 1;
        long long res = 0;
        while (l <= r) {
            res += a[r];
            if (l != r) {
                res -= a[l];
            }
            l++;
            r--;
        }
        return res;
    }
};
