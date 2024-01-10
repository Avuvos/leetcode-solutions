class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        int maxDiag = 0, maxArea = 0;
        for (int i = 0; i < d.size(); i++) {
            int h = d[i][0], w = d[i][1];
            int diag = h * h + w * w;
            if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = h * w;
            } else if (diag == maxDiag && h * w > maxArea) {
                maxArea = h * w;
            }
        }
        return maxArea;
    }
};
