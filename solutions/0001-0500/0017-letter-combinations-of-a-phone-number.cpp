class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        map<int, string> mp = {{2, "abc"}, {3, "def"}, {4, "ghi"}, 
                               {5, "jkl"}, {6, "mno"}, {7, "pqrs"},
                               {8, "tuv"}, {9, "wxyz"}};
        function<void(int, string&)> dfs = [&](int index, string& current) {
            if (index >= digits.size()) {
                if (current.size() > 0) ans.push_back(current);
                return;
            }
            
            for (auto &c: mp[digits[index] - '0']) {
                current.push_back(c);
                dfs(index + 1, current);
                current.pop_back();
            }
        };
        string current;
        dfs(0, current);
        return ans;
    }
};
