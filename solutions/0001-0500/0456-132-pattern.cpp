class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //fix index j
        //we now want to find the SMALLEST from left
        //and the LARGEST from right (that im still larger than him)
        int n = (int) nums.size();
        multiset<int> suffix;
        for (int i = 1; i < n; i++) {
            suffix.insert(nums[i]);
        }
        int minPrefix = nums[0];
        for (int j = 1; j < n; j++) {
            suffix.erase(suffix.find(nums[j]));
            auto it = suffix.lower_bound(nums[j]);
            if (it != suffix.begin()) {
                int cur = *prev(it);
                if (cur < nums[j] && cur > minPrefix) {
                    return true;
                }
            }
            minPrefix = min(minPrefix, nums[j]);
        }
        return false;
    }
};
