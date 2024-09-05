class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        vector<int> ans;
        //sum of rolls + n * sum of my roles / n + m = mean
        //<-> (n+m) * mean = sum of rolles
        //(n + m) * mean = sum of roles of m + sum of roles of n
        //sum of roles of n = (n+m)*mean - sum of roles of n
        int required_sum = (n + m) * mean - accumulate(rolls.begin(), rolls.end(), 0);
        
        auto possible = [&](int rolls, int target) -> bool {
            int min_value = rolls * 1;
            int max_value = rolls * 6;
            return target >= min_value && target <= max_value;
        };
        
        for (int i = 0; i < n; i++) {
            int rolls_left = n - i;
            bool found = false;
            for (int d = 6; d >= 1; d--) {
                if (possible(rolls_left - 1, required_sum - d)) {
                    required_sum -= d;
                    ans.push_back(d);
                    found = true;
                    break;
                }
            }
            if (!found) {
                return {};
            }
        }
        return ans;
    }
};
