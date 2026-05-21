class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int> ans(2, 0);
        for (auto &e: events) {
            if (e == "W") {
                ans[1]++;
            } else if (e == "WD" || e == "NB") {
                ans[0]++;
            } else {
                ans[0] += stoi(e);
            }
            if (ans[1] == 10) break;
        }
        return ans;
    }
};
