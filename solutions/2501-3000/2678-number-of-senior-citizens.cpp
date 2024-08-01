class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto &p: details) {
            int age = (p[11]-'0') * 10 + (p[12] - '0');
            if (age > 60) {
                ans++;
            }
        }
        return ans;
    }
};
