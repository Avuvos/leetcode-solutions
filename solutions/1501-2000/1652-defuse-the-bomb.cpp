class Solution {
public:
    //O(n) time & space
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ps(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++) {
            ps[i + 1] = ps[i] + code[i % n];
        }
        for (int i = 0; i < n; i++) {
            if (k > 0) {
                code[i] = ps[i + 1 + k] - ps[i + 1];
            } else if (k < 0) {
                code[i] = ps[i + n] - ps[i + n + k];
            } else {
                code[i] = 0;
            }
        }
        return code;
    }
};
