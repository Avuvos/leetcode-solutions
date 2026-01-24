class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        sort(towers.begin(), towers.end());
        vector<int> res = {-1, -1};
        int mx_q = -1;
        int cx = center[0], cy = center[1];
        for (auto &t: towers) {
            int x = t[0], y = t[1], q = t[2];
            int d = abs(x - cx) + abs(y - cy);
            if (d <= radius && q > mx_q) {
                res[0] = x;
                res[1] = y;
                mx_q = q;
            }
        }
        return res;
    }
};
