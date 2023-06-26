typedef long long ll;
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        ll res = 0, p1 = candidates, p2 = n - candidates - 1; 
        priority_queue<ll, vector<ll>, greater<>> pq1, pq2;
        int i = 0, j = n - 1;
        int cnt = 0;
        while (i <= j && cnt < 2*candidates) {
            if (i < j) {
                pq1.push(costs[i++]);
                pq2.push(costs[j--]);
               // cout << pq1.top() << " " << pq2.top() << " " << '\n';
                cnt++;
            } else {
                pq1.push(costs[i++]);
            }
            cnt++;
        }
        
        
        
        while (k--) {
            //cout << pq1.top() << " " << pq2.top() << " " << '\n';
            if ((!pq1.empty() && !pq2.empty() && pq1.top() <= pq2.top()) || pq2.empty()) {
                res += pq1.top();
                pq1.pop();
                if (p1 <= p2) {
                    pq1.push(costs[p1]);
                    p1++;
                }
            } else {
                res += pq2.top();
                pq2.pop();
                if (p2 >= p1) {
                    pq2.push(costs[p2]);
                    p2--;
                }
            }
        }
        return res;
        
        
    }
};
