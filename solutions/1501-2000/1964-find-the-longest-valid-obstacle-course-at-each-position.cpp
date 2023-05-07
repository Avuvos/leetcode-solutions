class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n, 0);
        vector<int> cur;
        for(int i = 0; i < obstacles.size(); i++) {
            auto it = upper_bound(cur.begin(), cur.end(), obstacles[i]);
            ans[i] = it - cur.begin() + 1;
            if (it==cur.end()) cur.push_back(obstacles[i]);
            else *it = obstacles[i];
        }
        return ans;
    }
};
