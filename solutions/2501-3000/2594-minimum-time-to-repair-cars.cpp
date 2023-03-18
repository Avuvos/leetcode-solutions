
class Solution {
public:
    typedef long long ll;
    const ll INF = 1e18;
    long long repairCars(vector<int>& ranks, int cars) {
        ll left = 1, right = INF, ans = INF;
        while (left <= right) {
            ll mid = left + (right - left)/2;
            ll sum = 0;
            for (auto &r: ranks) {
                sum += (ll) sqrt(mid/r);
            }
            if (sum >= cars) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;

    }
};
