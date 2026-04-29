class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        int a = sides[0], b = sides[1], c = sides[2];
        if (a + b <= c || b + c <= a || a + c <= b) {
            return {};
        }

        auto get = [&](int a, int b, int c) -> double {
            double angle = acos(1.0 * (b*b + c*c - a*a) / (2*b*c));
            return angle * (180.0 / numbers::pi);
        };

        double alpha = get(a, b, c);
        double beta = get(b, a, c);
        double gamma = get(c, b, a);
        vector<double> ans = {alpha, beta, gamma};
        sort(ans.begin(), ans.end());
        return ans;

    }
};
