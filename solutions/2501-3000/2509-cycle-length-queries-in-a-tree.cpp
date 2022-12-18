class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            long long a = queries[i][0], b = queries[i][1];
            long long atmp = a, btmp = b;
            int ah = 0, bh = 0;
            while (atmp != 1) {
                atmp /= 2;
                ah++;
            }
            while (btmp != 1) {
                btmp /= 2;
                bh++;
            }
            int len = 1;
            if (ah < bh) {
                swap(a, b);
                swap(ah, bh);
            }
            while (ah != bh) {
                a /= 2;
                len++;
                ah--;
            }
            
            while (a != b) {
                if (a != 1) {
                    len++;
                    a /= 2;
                } 
                if (b != 1){
                    len++;
                    b /= 2;
                } 
            }
            ans[i] = len;
        }
        return ans;
    }
};
