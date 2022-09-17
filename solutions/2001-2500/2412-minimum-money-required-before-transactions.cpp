typedef long long ll;
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        int n = transactions.size();
        vector<ll> diff(n);
        ll best = 0, money = 0;
        for (int index = 0; index < n; ++index) {
            ll diff = transactions[index][1] - transactions[index][0];
            if (diff < 0) money += abs(diff);
        }

        for (int index = 0; index < n; ++index) {
            best = max(best, money - max(0, transactions[index][0] - transactions[index][1]) + transactions[index][0]);
        }

        return best;
    }
};
