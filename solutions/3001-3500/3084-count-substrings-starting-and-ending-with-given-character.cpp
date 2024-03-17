class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long ans = 0;
        long long sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) {
                ans += sum;
                sum += 1;
            } 
        }
        return ans + sum;
    }
};
