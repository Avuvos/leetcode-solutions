class Solution {
public:
    int countPairs(vector<int>& nums) {
        int ans = 0, n = (int) nums.size();
        
        auto check = [&](int i, int j) -> bool {
            
            string s = to_string(nums[i]), t = to_string(nums[j]);
            
            for (int x = 0; x < s.size(); x++) {
                for (int y = x; y < s.size(); y++) {
                    string cs = s;
                    cs[x] = s[y];
                    cs[y] = s[x];
                    if (stoi(cs) == stoi(t)) {
                        return true;
                    }
                }
            }
            
            
            for (int x = 0; x < t.size(); x++) {
                for (int y = x; y < t.size(); y++) {
                    string ct = t;
                    ct[x] = t[y];
                    ct[y] = t[x];
                    if (stoi(ct) == stoi(s)) {
                        return true;
                    }
                }
            }
            
            return false;
            
        };
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += check(i, j);
            }
        }
        return ans;
    }
};
