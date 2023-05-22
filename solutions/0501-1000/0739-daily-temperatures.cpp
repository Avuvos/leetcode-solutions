class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = (int) t.size();
        vector<int> ans(n, 0);
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && t[stk.back()] < t[i]) {
                ans[stk.back()] = i - stk.back();
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return ans;
    }
};
