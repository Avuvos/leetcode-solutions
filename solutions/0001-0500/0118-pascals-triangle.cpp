class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0].push_back(1);
        for (int i = 1; i < numRows; i++) {
            for (int j = 0; j <= i; j++) {
                int current = 0;
                if (j > 0) current += ans[i - 1][j - 1];
                if (j < ans[i - 1].size()) current += ans[i - 1][j];
                ans[i].push_back(current);
            }
        }
        return ans;
    }
};
