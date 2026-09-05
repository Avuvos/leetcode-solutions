class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size(), m = shifts.size();
        vector<long long> ps(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + tasks[i];
        }
        vector<int> ans(m);
        int last = 0, rem = tasks[0];
        for (int i = 0; i < m; i++) {
            // Can't finish current task
            if (shifts[i] - rem < 0) {
                ans[i] = n - last;
                rem -= shifts[i];
                continue;
            }

            // Finished all tasks
            if (shifts[i] >= ps[n] - ps[last] - (tasks[last] - rem)) {
                ans[i] = 0;
                last = 0;
                rem = tasks[0];
                continue;
            }

            // Find the last task that we finish, and propagte delta for next shift
            int left = last, right = n - 1, res = last;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                long long req_sum = ps[mid + 1] - ps[last] - (tasks[last] - rem);
                if (shifts[i] >= req_sum) {
                    res = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            ans[i] = n - res - 1;
            long long extra = shifts[i] - (ps[res + 1] - ps[last] - (tasks[last] - rem));
            rem = tasks[res + 1] - extra;
            last = res + 1;
        }
        return ans;
    }
};
