class Solution {
public:
    long long minimumCost(string s) {
        long long n = (int) s.size();
        auto calc = [&](char c) {
            long long cur = 1e18;
            //ps[i] - cost to fix up to prefix i
            //sf[i] - cost to fix up to suffix i
            //ans is min(prefix[i] + suffix[i + 1]) for all i.
            vector<long long> ps(n + 1, 0);
            for (long long i = 0; i < n; i++) {
                if (i > 0) ps[i] += ps[i - 1];
                if (s[i] != c) {
                    if (i > 0 && s[i - 1] != c) {
                        //someone already payed for us
                        ps[i] += 1;
                    } else {
                        //starting new sequence, pay for ourselves
                        ps[i] += i + 1;
                    }
                    //pay extra to fix the prefix
                    if (i > 0 && s[i - 1] != s[i]) {
                        ps[i] += i;
                    }
                }
            }
            vector<long long> sf(n + 1, 0);
            for (long long i = n - 1; i >= 0; i--) {
                sf[i] = sf[i + 1];
                if (s[i] != c) {
                    if (i + 1 < n && s[i + 1] != c) {
                        //someone already payed for us
                        sf[i] += 1; 
                    } else {
                        //starting new sequence, pay for ourselves
                        sf[i] += (n - i);
                    }
                    
                    //pay extra to fix the suffix
                    if (i + 1 < n && s[i + 1] != s[i]) {
                        sf[i] += (n - i - 1);
                    }
                }
            }
            for (long long i = 0; i < n; i++) {
                cur = min(cur, ps[i] + sf[i + 1]);
            }
            return cur;
        };
        
        long long ans = min(calc('0'), calc('1'));
        return ans;
    }
};
