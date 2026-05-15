class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), pc(2);
        for (int i = n - 1; i >= 0; i--) {
            int p = nums[i] % 2;
            ans[i] = pc[p ^ 1];
            pc[p]++;
        }
        return ans;
    }
};
