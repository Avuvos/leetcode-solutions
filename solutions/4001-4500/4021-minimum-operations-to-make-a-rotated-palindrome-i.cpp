class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        auto get = [&](string& t) -> int {
            int l = 0, r = n - 1, cnt = 0;
            while (l < r) {
                int x = t[l] - 'a', y = t[r] - 'a';
                if (x > y) swap(x, y);
                cnt += min(y - x, 26 - y + x);
                l++;
                r--;
            }
            return cnt;
        };

        int ans = 1e9 + 2;
        for (int i = 0; i < n; i++) {
            string t = s.substr(i) + s.substr(0, i);
            ans = min(ans, i + get(t));
        }
        return ans;
    }
};
