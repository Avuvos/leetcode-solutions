class Solution {
public:
    int countPairs(vector<int>& nums) {

        int ans = 0, n = (int) nums.size();
        sort(nums.begin(), nums.end());
        vector<unordered_set<int>> vars(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            string s = to_string(nums[i]);
            int sz = (int) s.size();
            for (int x = 0; x < sz; x++) {
                for (int y = x; y < sz; y++) {
                    for (int j = 0; j < sz; j++) {
                        for (int k = j; k < sz; k++) {
                            swap(s[x], s[y]);
                            swap(s[j], s[k]);
                            int cand = stoi(s);
                            if (vars[i].find(cand) == vars[i].end()) {
                                ans += mp[cand];
                                vars[i].insert(cand);
                            }
                            swap(s[j], s[k]);
                            swap(s[x], s[y]);
                        }
                    }
                }
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};
