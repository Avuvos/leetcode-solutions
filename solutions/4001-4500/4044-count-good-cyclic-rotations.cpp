class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ps(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++) {
            ps[i + 1] = ps[i] + nums[i % n];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int mid = i + n / 2;
            ans += (ps[i + n] - ps[mid] > ps[mid] - ps[i]);
        }
        return ans;
    }
};
