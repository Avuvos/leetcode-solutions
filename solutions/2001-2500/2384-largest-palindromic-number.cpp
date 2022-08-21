class Solution {
public:
    string largestPalindromic(string num) {
        
        int counter[15] = {};
        for (auto a: num) {
            counter[a - '0']++;
        }
        string forward;
        string backward;

        bool found_mid = false;
        string mid;

        for (int i = 9; i >= 0; i--) {
            if (i == 0 && forward.size() == 0 && !found_mid) return "0";
            else if (i == 0 && forward.size() == 0) break;
            int bound = counter[i] / 2;
            for (int j = 0; j < bound; j++) {
                forward += to_string(i);
                backward += to_string(i);
             }
             if (counter[i] % 2 == 1 && !found_mid) {
                 found_mid = true;
                 mid += to_string(i);
             }
        }
        reverse(backward.begin(), backward.end());
        string ans = forward;
        if (mid.size() > 0) ans += mid;
        ans += backward;
        return ans;
    }
};
