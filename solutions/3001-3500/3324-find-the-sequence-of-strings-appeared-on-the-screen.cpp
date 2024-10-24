class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string prev = "";
        for (auto &c: target) {
            for (char d = 'a'; d <= c; d++) {
                ans.push_back(prev + d);
            }
            prev = ans.back();
        }
        return ans;
    }
};
