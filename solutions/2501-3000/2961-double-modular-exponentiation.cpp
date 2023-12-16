class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        auto expo = [&](int a, int b, int m) {
            long long res = 1;
            while (b > 0) {
                if (b & 1) {
                    res *= a;
                    res %= m;
                }
                a *= a;
                a %= m;
                b >>= 1;
            }
            return res;
        };
        vector<int> ans;
        for (int i = 0; i < variables.size(); i++) {
            int a = variables[i][0], b = variables[i][1], c = variables[i][2], m = variables[i][3];
            long long f = expo(a, b, 10);
            f = expo(f, c, m);
            if (f == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
