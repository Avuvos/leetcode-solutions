class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len = original.size();
        if (n * m != len) {
            return {};
        }
        vector<vector<int>> ans(m, vector<int>(n));
        int i = 0, j = 0;
        for (int index = 0; index < len; index++) {
            ans[i][j] = original[index];
            j++;
            if (j == n) {
                i++;
                j = 0;
            }
        }
        return ans;
    }
};
