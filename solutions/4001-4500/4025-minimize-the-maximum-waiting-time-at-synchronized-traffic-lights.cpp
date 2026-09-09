class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int mx = *max_element(lights.begin(), lights.end()), ans = 0;
        for (auto& t: arrivalTime) {
            int r = t % period;
            if (r >= mx) {
                ans = max(ans, period - r);
            }
        }
        return ans;
    }
};
