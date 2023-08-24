class Solution {
public:
    int minimumSum(int n, int k) {
        int num = 1;
        set<int> s;
        int sum = 0;
        while (n--) {
            while (s.find(k - num) != s.end()) {
                num++;
            }
            s.insert(num);
            sum += num;
            num++;
        }
        return sum;
    }
};
