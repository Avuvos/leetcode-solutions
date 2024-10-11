class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        set<int> alive;
        for (int i = 0; i < n; i++) {
            alive.insert(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<array<int, 3>> intervals(n);
        for (int i = 0; i < n; i++) {
            intervals[i] = {times[i][0], times[i][1], i};
        }
        sort(intervals.begin(), intervals.end());
        for (auto [l, r, idx]: intervals) {
            while (!pq.empty() && pq.top().first <= l) {
                auto [_, chair] = pq.top();
                alive.insert(chair);
                pq.pop();
            }
            int cur = *alive.begin();
            if (idx == targetFriend) {
                return cur;
            }
            alive.erase(cur);
            pq.push({r, cur});
        }
        return -1;
    }
};
