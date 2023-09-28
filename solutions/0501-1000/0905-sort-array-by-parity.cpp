class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int odds = 0, evens = 0;
        for (auto &x: nums) {
            if (x & 1) odds++;
            else evens++;
        }
        int e = 0, o = evens;
        while (e < evens && o < nums.size()) {
            while (e < evens && nums[e] % 2 == 0) {
                e++;
            }
            while (o < nums.size() && nums[o] % 2 == 1) {
                o++;
            }
            if (o < nums.size() && e < evens) {
                swap(nums[e], nums[o]);
                e++;
                o++;
            }
        }
        return nums;
    }
};
