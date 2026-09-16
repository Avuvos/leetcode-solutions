class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        int ans = 1, last_speed = speed[n - 1], last_pos = position[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (last_pos - position[i] > distance && speed[i] <= last_speed) {
                last_speed = speed[i];
                ans++;
            }
            last_pos = position[i];
        }
        return ans;
    }
};
