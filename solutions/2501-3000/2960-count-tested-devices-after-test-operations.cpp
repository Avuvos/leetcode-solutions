class Solution {
public:
    int countTestedDevices(vector<int>& a) {
        int d = 0;
        for (int i = 0; i < a.size(); i++) {
            a[i] -= d;
            if (a[i] > 0) {
                d++;
            }
        }
        return d;
    }
};
