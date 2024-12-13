class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        if (nums.back() < k) {
            return -1;
        }
        set<int> uniq;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= k) break;
            uniq.insert(nums[i]);
        }
        return uniq.size();
    }
};
