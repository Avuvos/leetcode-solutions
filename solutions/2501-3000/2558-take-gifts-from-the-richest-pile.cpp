typedef long long ll;
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<ll> pq;
        for (auto g: gifts) pq.push(g);
        
        ll res = 0;
        while (k--) {
            ll cur = pq.top();
            pq.pop();
            ll sq = (ll) sqrt(cur);
            pq.push(sq);
        }
        while (!pq.empty()) {
            res += pq.top(); pq.pop();
        }
        
        return res;
        
        
    }
};
