class Solution {
public:
    int minimumOperations(string num) {
        int n = (int) num.size();
        bool hasZero = false;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                hasZero = true;
            }
        }
        
        auto get = [&](char a, char b) {
            bool seen_a = false, seen_b = false;
            int cnt = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (num[i] == a && !seen_a) {
                    seen_a = true;
                } else if (num[i] == b && !seen_b && seen_a) {
                    seen_b = true;
                } else {
                    cnt++;
                }
                if (seen_a && seen_b) break;
            }
            if (!seen_a || !seen_b) {
                return hasZero ? n - 1 : n;
            }
            return cnt;
        };
        
        return min({get('0', '0'), get('5', '2'), get('5', '7'), get('0', '5')});
        
    }
};
