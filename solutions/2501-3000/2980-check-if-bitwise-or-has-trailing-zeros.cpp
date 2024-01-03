class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int even = 0;
        for (int i = 0; i < nums.size(); i++) {
            even += (nums[i] % 2 == 0);
        }
        return even >= 2;
    }
};
