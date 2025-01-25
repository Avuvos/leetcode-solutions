class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int ans = events[0][0], max_time = events[0][1];
        for (int i = 1; i < events.size(); i++) {
            int d = events[i][1] - events[i - 1][1];
            if (d > max_time) {
                max_time = d;
                ans = events[i][0];
            } else if (d == max_time) {
                ans = min(ans, events[i][0]);
            }
        }
        return ans;
    }
};
