class Solution {
public:

    struct Line {
        long long m, b;
        long long calc(long long x) {
            return m * x + b;
        }
    };
    
    struct CHT {
        deque<Line> dq;

        bool bad(Line l1, Line l2, Line l3) {
           return (l3.b - l1.b) * (l1.m - l2.m) <= (l2.b - l1.b) * (l1.m - l3.m);
        }

        void add(Line line) {
            while (dq.size() >= 2 && bad(dq[dq.size() - 2], dq[dq.size() - 1], line)) {
                dq.pop_back();
            }
            dq.push_back(line);
        }

        long long query(long long x) {
            while (dq.size() >= 2 && dq[0].calc(x) >= dq[1].calc(x)) {
                dq.pop_front();
            }
            return dq[0].calc(x);
        }
    };

    long long minPartitionScore(vector<int>& nums, int k) {
        const long long INF = 1e18 + 2;
        int n = nums.size();
        vector<long long> ps(n + 1);
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + nums[i];
        }
        
        // dp[t][i] - min score up to i using t splits
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
        dp[0][0] = 0;
        for (int t = 1; t <= k; t++) {
            Line l0(-ps[0], dp[t - 1][0] + (ps[0] * ps[0] - ps[0]) / 2);
            CHT cht;
            cht.add(l0);
            for (int i = 1; i <= n; i++) {
                long long x = ps[i];
                dp[t][i] = (x * x + x) / 2 + cht.query(x);
                if (dp[t - 1][i] < INF) {
                    Line li(-ps[i], dp[t - 1][i] + (ps[i] * ps[i] - ps[i]) / 2);
                    cht.add(li);
                }
            }
        }
        return dp[k][n];
    }
};
