class Solution {
public:
    int ans[101];
    int dfs(int index, string s) {
        if (index >= s.size()) {
            return 1;
        }
        if (index == s.size() - 1) {
            return s[index] == '0' ? 0 : 1;
        }
        
        if (s[index] == '0') {
            return 0;
        }
        if (ans[index] != -1){
            return ans[index];
        }
        int take_one = dfs(index + 1, s);
        int take_two = 0;
        if (s[index] == '1' || (s[index] == '2' && s[index + 1] < '7')) {
            take_two = dfs(index + 2, s);
        }
        ans[index] = take_one + take_two;
        return ans[index];
    }
    
    int numDecodings(string s) {
        fill(begin(ans), end(ans), -1);
        return dfs(0, s);
    }
};
