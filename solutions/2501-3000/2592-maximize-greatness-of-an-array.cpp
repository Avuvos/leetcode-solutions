class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int p = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[p])
                p++;
        }
        return p;
    }
};
