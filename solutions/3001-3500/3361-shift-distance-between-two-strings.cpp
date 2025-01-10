class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        int n = s.size();
        
        auto get = [&](int i) -> long long {
            if (s[i] == t[i]) return 0;
            long long up = 0, down = 0;
            int c = s[i];
            // go up
            while (c != t[i]) {
                up += nextCost[c - 'a'];
                if (c == 'z') {
                    c = 'a';
                } else {
                    c = (char) (c + 1);
                }
            }
            c = s[i];
            // go down
            while (c != t[i]) {
                down += previousCost[c - 'a'];
                if (c == 'a') {
                    c = 'z';
                } else {
                    c = (char) (c - 1);
                }
            }
            return min(down, up);
        };
        
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += get(i);
        }
        return ans;
    }
};
