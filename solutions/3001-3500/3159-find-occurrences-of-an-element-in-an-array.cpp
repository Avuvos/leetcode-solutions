class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> pos;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                pos.push_back(i);
            }
        }
        int q = (int) queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int k = queries[i];
            k--;
            ans[i] = (k < pos.size() ? pos[k] : -1);
        }
        return ans;
    }
};
