class Solution {
public:
    int largestVariance(string s) {
        vector<int> counter(26, 0);
        for (auto &c: s) counter[c - 'a']++;
        
        auto kadane = [&](char c1, char c2) {
            int res = 0, cur = 0;
            int cnt_max = 0, cnt_min = 0, min_cnt = counter[c2 - 'a'];
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == c1) cnt_max++;
                if (s[i] == c2) {
                    cnt_min++;
                    min_cnt--;
                }
                if (cnt_min > 0) {
                    res = max(res, cnt_max - cnt_min);
                }
                if (cnt_max < cnt_min && min_cnt > 0) {
                    cnt_max = 0;
                    cnt_min = 0;
                }
            }
            return res;
        };
        
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            for (char d = 'a'; d <= 'z'; d++) {
                if (c == d) continue;
                ans = max(ans, kadane(c, d));
            }
        }
        return ans;
    }
};
