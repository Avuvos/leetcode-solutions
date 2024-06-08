class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        map<int, int> mp;
        map<int, int> wins;
        int mx = *max_element(skills.begin(), skills.end());
        int n = (int) skills.size();
        deque<int> q;
        for (int i = 0; i < n; i++) {
            mp[skills[i]] = i;
            q.push_back(skills[i]);
        }
        
        while (true) {
            int f = q.front(); q.pop_front();
            int s = q.front(); q.pop_front();
            if (f == mx) {
                return mp[f];
            }
            if (s == mx) {
                return mp[s];
            }
            if (f > s) {
                wins[f] += 1;
                wins[s] = 0;
                if (wins[f] >= k) {
                    return mp[f];
                }
                q.push_front(f);
                q.push_back(s);
            } else {
                wins[s] += 1;
                wins[f] = 0;
                if (wins[s] >= k) {
                    return mp[s];
                }
                q.push_front(s);
                q.push_back(f);
            }
        }
        
        return -1;
        
    }
};
