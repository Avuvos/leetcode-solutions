class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int last = points[0][0] + w;
        int ans = 1;
        for (int i = 1; i < points.size(); i++) {
            if (last < points[i][0]) {
                ans++;
                last = points[i][0] + w;
            }
            
        }
        return ans;
    }
};
