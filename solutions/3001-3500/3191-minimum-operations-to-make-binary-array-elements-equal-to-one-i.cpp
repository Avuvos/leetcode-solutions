class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, n = (int) nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == 0) {
                ans++;
                nums[i] = 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
            }
        }
        
        if (all_of(nums.begin(), nums.end(), [&](int x) {return x == 1;})){
            return ans;
        }
        
        return -1;
        
    }
};
