class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = (int) dist.size();
        vector<int> time(n);
        for (int i = 0; i < n; i++) {
            time[i] = (dist[i] + speed[i] - 1) / speed[i];
        }
        sort(time.begin(), time.end());
        int delta = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            time[i] -= delta;
            if (time[i] <= 0) {
                break;
            }
            delta++;
            ans++;
        }
        return ans;
    }
};
