class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> mp;
        for (int a = 1; a <= 1000; a++) {
            for (int b = a; b <= 1000; b++) {
                int x = a * a * a + b * b * b;
                if (x > n) break;
                mp[x]++;
            }
        }
        vector<int> ans;
        for (auto [k, v]: mp) {
            if (v >= 2) {
                ans.push_back(k);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
