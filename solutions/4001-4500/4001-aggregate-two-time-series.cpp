class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int n = series1.size(), m = series2.size();
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while (i < n || j < m) {
            if (i >= n) {
                ans.push_back(series2[j++]);
                continue;
            }
            if (j >= m) {
                ans.push_back(series1[i++]);
                continue;
            }
            int ts1 = series1[i][0], ts2 = series2[j][0];
            int ts = min(ts1, ts2);
            int val = series1[i][1] + series2[j][1];
            ans.push_back({ts, val});
            if (ts1 == ts2) {
                i++;
                j++;
            } else if (ts1 < ts2) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};
