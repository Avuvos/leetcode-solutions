class Solution {
public:
    vector<int> calc_divs(int n) {
        vector<int> divs;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divs.push_back(i);
                if (n / i != i) {
                    divs.push_back(n / i);
                }
            }
        }
        return divs;
    }
    vector<int> minDifference(int n, int k) {
        auto divs = calc_divs(n);
        map<int, vector<int>> num_to_divs;
        for (auto &num: divs) {
            num_to_divs[num] = calc_divs(num);
        }
        const int INF = 1e9 + 2;
        auto f = [&](auto &f, int num, int count, vector<int>& cur) -> pair<int, vector<int>> {
            if (count == 0 && num == 1) {
                if (cur.empty()) {
                    return {INF, cur};
                }
                sort(cur.begin(), cur.end());
                return {cur.back() - cur[0], cur};
            }
            if (count == 0 && num != 1) {
                return {INF, cur};
            }
            vector<int> result;
            int best = INF;
            for (auto &div: num_to_divs[num]) {
                vector<int> next_cur = cur;
                next_cur.push_back(div);
                auto [diff, vec] = f(f, num / div, count - 1, next_cur);
                next_cur.pop_back();
                if (diff <= best) {
                    best = diff;
                    result = vec;
                }
            }
            return {best, result};
        };
        vector<int> empty;
        return f(f, n, k, empty).second;
    }
};
