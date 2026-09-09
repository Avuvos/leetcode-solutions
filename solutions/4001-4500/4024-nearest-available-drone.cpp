class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int idx = -1, best = 1e9;
        for (int i = 0; i < drones.size(); i++) {
            int d = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);
            if (d <= drones[i][2] && d < best) {
                best = d;
                idx = i;
            }
        }
        return idx;
    }
};
