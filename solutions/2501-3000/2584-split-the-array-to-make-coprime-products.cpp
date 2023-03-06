class Solution {
public:
    typedef long long ll;
    int findValidSplit(vector<int>& nums) {
        int n = 1e6 + 1;
        vector<int> is_prime(n + 1, -1);
        is_prime[0] = is_prime[1] = -2;
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i] == -1) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = i;
            }
        }
        
        unordered_multiset<int> suffix;
        unordered_set<int> pref;
        int N = nums.size();
        for (int i = 1; i < N; i++) {
            int num = nums[i];
            while (is_prime[num] > 0) {
                suffix.insert(is_prime[num]);
                num /= is_prime[num];
            }
            if (is_prime[num] == -1) {
                suffix.insert(num);
            }
        }
        
        
        for (int i = 0; i < N - 1; i++) {
            unordered_multiset<int> cur;
            int num = nums[i];
            while (is_prime[num] > 0) {
                cur.insert(is_prime[num]);
                if (i > 0) suffix.erase(suffix.find(is_prime[num]));
                pref.insert(is_prime[num]);
                num /= is_prime[num];
            }
            if (is_prime[num] == -1) {
                if (i > 0) suffix.erase(suffix.find(num));
                pref.insert(num);
                cur.insert(num);
            }
            // for (auto &s: cur) {
            //     if (i > 0)
            //         suffix.erase(suffix.find(s));
            //     pref.insert(s);
            // }
            bool ok = true;
            for (auto &s: pref) {
                if (suffix.find(s) != suffix.end()) {
                    ok = false;
                    break;
                }
            }
            if (ok) return i;
        }
        return -1;
    }
};
