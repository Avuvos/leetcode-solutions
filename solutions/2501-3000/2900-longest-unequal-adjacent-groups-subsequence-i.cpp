class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        auto calc = [&](int x) {
            vector<string> ans;
            for (int i = 0; i < groups.size(); i++) {
                if (groups[i] == x) {
                    ans.push_back(words[i]);
                    x ^= 1;
                }
            }
            return ans;
        };
        vector<string> op1 = calc(0);
        vector<string> op2 = calc(1);
        return op1.size() > op2.size() ? op1 : op2;
    }
};
