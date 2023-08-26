class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = (int) pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(dp.begin(), dp.end(), pairs[i][0]);
            if (it == dp.end()) dp.push_back(pairs[i][1]);
            else if (pairs[i][1] < *it) *it = pairs[i][1];
        }
        return (int) dp.size();
    }
};
