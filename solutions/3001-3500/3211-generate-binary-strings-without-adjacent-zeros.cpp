class Solution {
public:
    vector<string> validStrings(int n) {
        auto dfs = [&](auto& dfs, string& current) -> vector<string> {
            if ((int) current.size() == n) {
                return {current};
            }
            vector<string> result;
            if (current.empty() || current.back() == '1') {
                string nxt = current + '0';
                auto zero = dfs(dfs, nxt);
                for (auto& s: zero) {
                    result.push_back(s);
                }
            }
            string nexto = current + '1';
            auto one = dfs(dfs, nexto);
            for (auto& s: one) {
                result.push_back(s);
            }
            return result;
        };
        
        string empty;
        return dfs(dfs, empty);
    }
};
