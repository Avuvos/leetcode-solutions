typedef long long ll;
class Solution {
public:
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mod = 1e9 + 7;
        vector<pair<int, int>> engineers(n);
        priority_queue<int, vector<int>, greater<>> pq;
        for (int index = 0; index < n; index++) {
            engineers[index] = {efficiency[index], speed[index]};
        }
        sort(engineers.rbegin(), engineers.rend());
        ll sum = 0, res = 0;
        for (int index = 0; index < n; index++) {
            pq.push(engineers[index].second);
            sum += engineers[index].second;
            if (pq.size() > k) {
                int curr = pq.top(); pq.pop();
                sum -= curr;
            }
            res = max(res, (engineers[index].first * sum));
        }
        return res % mod;
    }
};
