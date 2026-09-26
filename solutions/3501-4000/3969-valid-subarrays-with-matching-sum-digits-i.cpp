class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            long long s = 0;
            for (int j = i; j < n; j++) {
                s += nums[j];
                int f = s % 10;
                long long ts = s;
                while (ts > 0) {
                    f = ts % 10;
                    ts /= 10;
                }
                ans += f == x && s % 10 == x;
            }
        }
        return ans;
    }
};
