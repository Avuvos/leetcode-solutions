class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target[i]) {
                st.insert(nums[i]);
            }
        }
        return st.size();
    }
};
