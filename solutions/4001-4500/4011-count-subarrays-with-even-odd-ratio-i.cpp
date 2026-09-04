class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> c(2);
            for (int j = i; j < n; j++) {
                c[nums[j] % 2]++;
                if (c[1] > 0 && c[0] * b <= c[1] * a) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
