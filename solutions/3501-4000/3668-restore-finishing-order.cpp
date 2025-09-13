class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans;
        for (auto &x: order) {
            auto it = lower_bound(friends.begin(), friends.end(), x);
            if (it != friends.end() && *it == x) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
