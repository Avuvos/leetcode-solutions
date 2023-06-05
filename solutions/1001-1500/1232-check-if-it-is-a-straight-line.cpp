class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        int dx = x1 - x2, dy = y1 - y2;
        for (int i = 2; i < coordinates.size(); i++) {
            int x = coordinates[i][0], y = coordinates[i][1];
            if ((dx) * (y - y1) != dy * (x - x1)) {
                return false;
            }
        }
        return true;
    }
};
