class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = (int) senate.size();
        set<int> rs, rd;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') rs.insert(i);
            else rd.insert(i);
        }
        
        vector<int> alive(n, true);
        int i = 0;
        while (!rs.empty() && !rd.empty()) {
            if (!alive[i]) {
                i++;
                i %= n;
                continue;
            };
            if (senate[i] == 'R') {
                auto it = rd.lower_bound(i);
                if (it == rd.end()) it = rd.begin();
                alive[*it] = false;
                rd.erase(*it);
            } else {
                auto it = rs.lower_bound(i);
                if (it == rs.end()) it = rs.begin();
                alive[*it] = false;
                rs.erase(*it);
            }
            i++;
            i %= n;
        }
        return rs.empty() ? "Dire" : "Radiant";
    }
};
