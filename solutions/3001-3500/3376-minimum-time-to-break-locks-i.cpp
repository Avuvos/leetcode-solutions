class Solution {
public:
    int findMinimumTime(vector<int>& s, int K) {
        int ans = 2e9;
        sort(s.begin(), s.end());
        
        do {
            int factor = 1;
            int time = 0;
            for (auto &x: s) {
                time += (x + factor - 1) / factor;
                factor += K;
            }
            ans = min(ans, time);
        } while (next_permutation(s.begin(), s.end()));
        
        return ans;
    }
};
