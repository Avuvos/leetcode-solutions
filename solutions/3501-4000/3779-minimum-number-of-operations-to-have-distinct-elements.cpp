class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (int i = n - 1; i >= 0; i--) {
            if (!st.insert(nums[i]).second) {
                return 1 + i / 3;
            }
        }
        return 0;
    }
};
