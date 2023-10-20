class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& tasks) {
        int n = (int) p.size();
        sort(tasks.begin(), tasks.end());
        sort(p.rbegin(), p.rend());
        int ans = 0;
        int curMax = 0;
        for (int i = 0, j = -1; i < 4*n; i++) {
            if (i % 4 == 0) {
                j++;
                curMax = 0;
            }
            curMax = max(curMax, p[j] + tasks[i]);
            ans = max(ans, curMax);
        }
        return ans;
    }
};
