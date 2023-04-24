class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto s: stones) pq.push(s);
        while (pq.size() > 1) {
            int p1 = pq.top(); pq.pop();
            int p2 = pq.top(); pq.pop();
            int mn = min(p1, p2);
            p1 -= mn;
            p2 -= mn;
            if (p2 > 0) pq.push(p2);
            if (p1 > 0) pq.push(p1);
        }
        return (pq.empty() ? 0 : pq.top());
    }
};
