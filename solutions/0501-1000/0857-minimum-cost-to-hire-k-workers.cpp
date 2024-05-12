class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = (int) wage.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](const int i, const int j){
           return (double)wage[i] / quality[i] < (double)wage[j] / (double)quality[j]; 
        });
        
        priority_queue<int> pq;
        const double INF = 1e18;
        double ans = INF, sum = 0;
        for (int i = 0; i < n; i++) {
            int j = order[i];
            sum += quality[j];
            pq.push(quality[j]);
            while (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ans = min(ans, wage[j] + (double) (sum - quality[j]) * wage[j] / quality[j]);
            }
        }
        
        return ans;
    }
};
