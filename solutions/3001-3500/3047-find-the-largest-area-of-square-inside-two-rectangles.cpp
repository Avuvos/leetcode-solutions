class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = (int) bottomLeft.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int x1 = bottomLeft[i][0], y1 = bottomLeft[i][1];
            int x2 = topRight[i][0], y2 = topRight[i][1];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int x3 = bottomLeft[j][0], y3 = bottomLeft[j][1];
                int x4 = topRight[j][0], y4 = topRight[j][1];
                
                int x_bot = max(x1, x3);
                int y_bot = max(y1, y3);
                
                int x_top = min(x2, x4);
                int y_top = min(y2, y4);
                
                if (x_bot > x_top || y_bot > y_top) continue;
                
                int width = x_top - x_bot;
                int height = y_top - y_bot;
                int side = min(width, height);
                ans = max(ans, 1LL * side * side);                
            }
        }
        return ans;
    }
};
