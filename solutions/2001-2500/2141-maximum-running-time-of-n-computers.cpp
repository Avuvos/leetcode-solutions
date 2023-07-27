class Solution {
public:
    typedef long long ll;
    long long maxRunTime(int n, vector<int>& batteries) {
        ll left = 0, right = 1e16, ans = 0;
        sort(batteries.begin(), batteries.end());

        auto good = [&](ll time) {
            int c = 0; //number of computers done
            ll current_time = 0;
            for (int i = 0; i < batteries.size(); i++) {
                if (current_time < time) {
                    current_time += batteries[i];
                }
                if (current_time >= time) {
                    current_time = current_time - time;
                    c++;
                }
            }
            return c >= n;
        };

        while (left <= right) {
            ll mid = left + (right - left)/2;
            if (good(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
