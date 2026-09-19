class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int prev = 0, ans = 0;
        for (auto &cur: requests) {
            ans += abs(prev - cur);
            prev = cur;
        }
        return ans;
    }
};
