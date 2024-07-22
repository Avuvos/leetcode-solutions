class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = (int) names.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](const int i, const int j){
            return heights[i] > heights[j];
        });
        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = names[order[i]];
        }
        return ans;
    }
};
