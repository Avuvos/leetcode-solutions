class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans = 0, best_score = -1;
        sort(divisors.begin(), divisors.end());
        for (auto &d: divisors) {
            int score = 0;
            for (auto &num: nums) {
                if (num % d == 0) {
                    score++;
                }
            }
            if (score > best_score) {
                best_score = score;
                ans = d;
            }
        }
        return ans;
    }
};
