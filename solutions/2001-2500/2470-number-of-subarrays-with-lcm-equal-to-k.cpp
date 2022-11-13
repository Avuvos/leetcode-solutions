class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long g = nums[i];
            if (g == k) res++;
            for (int j = i + 1; j < nums.size(); j++) {
                g = lcm(g, nums[j]);
                if (g > k) break;
                if (g == k) res++;
            }
        }
        return res;
    }
};
