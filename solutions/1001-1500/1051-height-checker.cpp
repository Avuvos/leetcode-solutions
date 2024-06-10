class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = (int) heights.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](const int i, const int j) {
           return heights[i] < heights[j]; 
        });
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (heights[i] != heights[order[i]]) {
                ans += 1;
            }
        }
        return ans;
    }
};
