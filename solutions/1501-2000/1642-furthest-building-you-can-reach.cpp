class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = (int) heights.size();
        priority_queue<int, vector<int>, greater<>> pq;
        for (int i = 1; i < n; i++) {
            if (heights[i] <= heights[i - 1]) {
                continue;
            }
            pq.push(heights[i] - heights[i - 1]);
            if (ladders > 0) {
                ladders--;
            } else if (bricks >= pq.top()) {
                bricks -= pq.top();
                pq.pop();
            } else {
                return i - 1;
            }
        }
        return n - 1;
    }
};
