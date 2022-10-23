class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int current = nums[i];
            if (current == k) res++;
            for (int j = i + 1; j < nums.size(); ++j) {
                current = gcd(current, nums[j]);
                if (current == k) res++;
            }
        }
        return res;
    }
};
