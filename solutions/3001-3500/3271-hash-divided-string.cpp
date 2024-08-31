class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.size();
        string result;
        for (int i = 0; i < n; i += k) {
            string sub = s.substr(i, k);
            int sum = 0;
            for (int j = 0; j < sub.size(); j++) {
                sum += (sub[j] - 'a');
                sum %= 26;
            }
            result += (char) (sum + 'a');
        }
        return result;
    }
};
