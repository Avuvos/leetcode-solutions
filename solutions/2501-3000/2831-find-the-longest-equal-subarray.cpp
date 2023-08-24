class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        //sliding window, save the cost, when we run out, we simply ditch the leftmost part.
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        
        int ans = 0;
        for (auto [key, v]: mp) {
            int curk = k, m = (int) v.size();
            int current_ans = 1;
            ans = max(ans, current_ans);
            queue<int> q;
            // cout << "current num is " << key << endl;
            // cout << "curk is " << curk << endl;
            for (int i = 1; i < m; i++) {
                int d = v[i] - v[i - 1] - 1;
                // cout << v[i] << " " << curk << " " << d << endl;
                while (!q.empty() && curk - d < 0) {
                    curk += q.front();
                    current_ans--;
                    q.pop();
                }
                if (curk - d >= 0) {
                    curk -= d;
                    current_ans++; //plus the current index
                    q.push(d);
                } else {
                    current_ans = 1;
                }
                ans = max(ans, current_ans);
            }
            
            ans = max(ans, current_ans);
            
        }
        
        return ans;
    }
};
