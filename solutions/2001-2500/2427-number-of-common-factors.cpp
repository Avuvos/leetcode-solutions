class Solution {
public:
    set<int> divisors(int num) {
        set<int> res;
        for (int i = 1; i <= num; i++) {
            if (num % i == 0) res.insert(i);
        }
        return res;
    }

    int commonFactors(int a, int b) {
        set<int> A = divisors(a);
        set<int> B = divisors(b);
        int res = 0;
        for (auto a: A) {
            res += B.count(a);
        }
        return res;
    }
};
