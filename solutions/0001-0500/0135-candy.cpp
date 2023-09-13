class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = (int) ratings.size(), sum = 0;
        vector<int> order(n), cnt(n, 1);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](const int &i, const int &j) {
            return ratings[i] < ratings[j];
        });
        for (auto &i: order) {
            if (i - 1 >= 0 && ratings[i] > ratings[i - 1]) {
                cnt[i] = max(cnt[i], cnt[i - 1] + 1);
            }
            if (i + 1 < n && ratings[i] > ratings[i + 1]) {
                cnt[i] = max(cnt[i], cnt[i + 1] + 1);
            }
            sum += cnt[i];
        }
        return sum;
    }
};
