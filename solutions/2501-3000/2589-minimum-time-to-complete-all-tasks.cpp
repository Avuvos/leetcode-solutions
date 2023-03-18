class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        const int N = 2005;
        sort(tasks.begin(), tasks.end(), [&](const vector<int>& t1, const vector<int>& t2) {
            return t1[1] < t2[1];
        });
        
        vector<int> on(N, false);
        for (auto &t: tasks) {
            int s = t[0], e = t[1], d = t[2];
            for (int i = s; i <= e && d > 0; i++) d -= on[i];
            while (d > 0) {
                if (!on[e]) d--;
                on[e--] = true;
            }
        }
        int ans = 0;
        for (int i = 1; i < N; i++) ans += on[i];
        return ans;
    }
};
