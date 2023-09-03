class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int n = low; n <= high; n++) {
            string s = to_string(n);
            if (s.size() & 1) continue;
            int sum = 0;
            for (int i = 0; i < s.size() / 2; i++) sum += (s[i] - '0');
            for (int i = s.size() / 2; i < s.size(); i++) sum -= (s[i] - '0');
            if (sum == 0) {
                ans++;
            }
        }
        return ans;
    }
};
