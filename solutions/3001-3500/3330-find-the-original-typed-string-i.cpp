class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 0;
        int streak = 1;
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == word[i - 1]) {
                streak++;
            } else {
                ans += streak - 1;
                streak = 1;
            }
        }
        ans += streak;
        return ans;
    }
};
