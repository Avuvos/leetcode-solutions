class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int left = 0, right = n - 1, score = 0, res = 0;
        sort(tokens.begin(), tokens.end());
        while (left <= right) {
            if (power >= tokens[left]) {
                score++;
                power -= tokens[left];
                left++;
                res = max(res, score);
            }
            else if (score >= 1) {
                score--;
                power += tokens[right];
                right--;
            }
            else {
                break;
            }
            res = max(res, score);
        }
        return res;
    }
};
