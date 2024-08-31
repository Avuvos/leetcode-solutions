class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<int> time(n);
        for (int i = 0; i < n; i++) {
            time[i] = (health[i] + power - 1) / power;
        }
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](const int i, const int j) {
            long long op_i = damage[i] * time[i] + (damage[j] * (time[i] + time[j]));
            long long op_j = damage[j] * time[j] + (damage[i] * (time[j] + time[i]));
            return op_i < op_j;
        });
        long long sum = accumulate(damage.begin(), damage.end(), 0);
        long long ans = sum;
        for (auto &idx: order) {
            ans += 1LL * time[idx] * sum;
            ans -= damage[idx];
            sum -= damage[idx];
        }
        return ans;
    }
};
