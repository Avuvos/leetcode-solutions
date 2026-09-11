class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<bool> seen(upper + 1, false);
        for (auto &x: nums) {
            if (x <= upper) seen[x] = true;
        }
        vector<vector<int>> ans;
        int x = lower;
        while (x <= upper) {
            int st = x;
            while (x <= upper && !seen[x]) {
                x++;
            }
            if (st != x) {
                ans.push_back({st, x - 1});
            }
            x++;
        }
        return ans;
    }
};
