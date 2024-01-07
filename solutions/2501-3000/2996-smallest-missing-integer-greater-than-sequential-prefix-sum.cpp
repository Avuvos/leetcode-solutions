class Solution {
public:
    int missingInteger(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int s = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] + 1 != nums[i]) {
                break;
            }
            s += nums[i];
        }
        while (st.find(s) != st.end()) {
            s++;
        }
        return s;
    }
};
