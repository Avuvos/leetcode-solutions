class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        int n = types.size();
        vector<array<int, 3>> stk;
        for (int i = 0; i < n; i++) {
            int t = types[i], c = colors[i];
            if (!stk.empty() && stk.back()[0] == t && stk.back()[1] == c) {
                stk.back()[2]++;
            } else {
                stk.push_back({t, c, 1});
            }
            if (stk.back()[2] % groupSize[t] == 0) {
                stk.pop_back();
            }
        }
        return stk.empty();
    }
};
