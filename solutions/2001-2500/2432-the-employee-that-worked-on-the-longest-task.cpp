class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int time = 0, res = 0;
        int prev = 0;
        for (auto log: logs) {
            int current = log[1] - prev;
            if (current > time) {
                time = current;
                res = log[0];
            }
            else if (current == time) {
                res = min(res, log[0]);
            }
            prev = log[1];
        }
        return res;
    }
};
