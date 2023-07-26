class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1, right = 1e7 + 17, ans = -1, n = dist.size();
        
        auto ok = [&](int speed) {
            double time = 0;
            for (int i = 0; i < n; i++) {
                int d = dist[i];
                int cur = (d + speed - 1)/speed;
                if (i < n - 1) time += max(1, cur);
                else time += d/(double)(speed);
            }
            return time <= hour;
        };
        
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (ok(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
