class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        vector<int> ans;
        for (auto &a: asteroids) {
            if (a > 0) {
                stk.push_back(a);
                continue;
            }
            while (!stk.empty() && stk.back() > 0 && stk.back() < abs(a)) {
                stk.pop_back();
            }
            
            if (!stk.empty() && stk.back() == abs(a)) {
                stk.pop_back();
                continue;
            }
            
            if (stk.empty() || stk.back() < 0) {
                stk.push_back(a);
            }
            
        }
        while (!stk.empty()) {
            ans.push_back(stk.back());
            stk.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
