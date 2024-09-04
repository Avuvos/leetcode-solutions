class Solution {
public:
    const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obs;
        for (auto &v: obstacles) {
            obs.insert({v[1], v[0]});
        }
        int x = 0, y = 0, dir = 0;
        int best = 0;
        for (auto &c: commands) {
            if (c == -2) {
                dir = (dir + 4 - 1) % 4;
            } else if (c == -1) {
                dir = (dir + 4 + 1) % 4;
            } else {
                auto [dx, dy] = DIRECTIONS[dir];
                for (int i = 0; i < c; i++) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (obs.contains({nx, ny})) {
                        break;
                    }
                    x = nx;
                    y = ny;
                    best = max(best, x * x + y * y);
                }
            }
        }
        return best;
    }
};
