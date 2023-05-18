class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        set<string> alive;
        for (auto &s: products) alive.insert(s);
        vector<vector<string>> ans;
        for (int i = 0; i < searchWord.size(); i++) {
            char c = searchWord[i];
            int cnt = 0;
            vector<string> to_ret;
            while (!alive.empty()) {
                string cur = *alive.begin();
                alive.erase(cur);
                if (i > cur.size() || cur[i] != c) {
                    continue;
                }
                to_ret.push_back(cur);
                cnt += 1;
            }
            vector<string> current;
            for (auto s: to_ret) {
                if (current.size() < 3) current.push_back(s);
                alive.insert(s);
            }
            ans.push_back(current);
        }
        return ans;
    }
};
