class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<long long> seen;
        priority_queue<long long, vector<long long>, greater<>> pq;
        pq.push(1);
        seen.insert(1);
        long long ans = -1;
        while (!pq.empty() && n > 0) {
            long long cur = pq.top(); pq.pop();
            ans = cur;
            for (auto p: {2, 3, 5}) {
                long long nxt = p * cur;
                if (!seen.contains(nxt)) {
                    seen.insert(nxt);
                    pq.push(nxt);
                }
            }
            n--;
        }
        return ans;
    }
};
