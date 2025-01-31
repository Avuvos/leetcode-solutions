class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> xs, ys;
        for (auto &r: rectangles) {
            xs.emplace_back(r[0], r[2]);
            ys.emplace_back(r[1], r[3]);
        }

        auto check = [&](vector<pair<int, int>>& positions) -> bool {
            sort(positions.begin(), positions.end());
            set<int> cands;
            for (auto &[l, r]: positions) {
                cands.insert(l);
                cands.insert(r);
            }
            cands.erase(cands.begin());
            cands.erase(prev(cands.end()));
            vector<int> cds;
            for (auto &c: cands) cds.push_back(c);
            sort(cds.begin(), cds.end());
            int cuts = 0;
            int i = 0;
            priority_queue<int, vector<int>, greater<>> pq;
            bool seenBefore = false;
            for (auto &c: cds) {

                while (i < positions.size() && positions[i].first < c) {
                    pq.push(positions[i].second);
                    i++;
                }
                
                while (!pq.empty() && pq.top() <= c) {
                    seenBefore = true;
                    pq.pop();
                }
                
                if (pq.empty() && seenBefore) {
                    seenBefore = false;
                    cuts++;
                }
                
            }
            return cuts >= 2;
        };
        
        
        return check(xs) || check(ys);
    }
};
