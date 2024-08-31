class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        
        //enumerate all the k-palindromes
        set<string> cands;
        auto dfs = [&](auto &dfs, int index, string& s) -> void {
            if (index >= (n + 1) / 2) {
                string t = s;
                if (n % 2 == 1) t.pop_back();
                reverse(t.begin(), t.end());
                string cand = s + t;
                if (stoll(cand) % k == 0) {
                    sort(cand.begin(), cand.end());
                    cands.insert(cand);
                }
                return;
            }
            for (int digit = '0'; digit <= '9'; digit++) {
                if (index == 0 && digit == '0') continue;
                s += digit;
                dfs(dfs, index + 1, s);
                s.pop_back();
            }
        };
        string empty;
        dfs(dfs, 0, empty);
        
        //use multi-choose to figure out how many options for each k-pal
        vector<long long> f(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            f[i] = i * f[i - 1];
        }
        long long ans = 0;
        for (auto &s: cands) {
            vector<int> cnt(10, 0);
            for (auto& d: s) {
                cnt[d - '0']++;
            }
            
            //choose from n - 1, cnt[0] places to place the zeros.
            long long ops = f[n - 1] / (f[cnt[0]] * f[n - 1 - cnt[0]]);
            
            //now just regular multi chosoe on n - cnt[0] elements.
            ops *= f[n - cnt[0]];
            for (int i = 1; i <= 9; i++) {
                ops /= f[cnt[i]];
            }
            ans += ops;
        }
        return ans;
    }
};
