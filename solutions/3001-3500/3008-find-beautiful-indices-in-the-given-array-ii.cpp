class Solution {
public:
    vector<int> computeLPS(string& pattern) {
        int m = (int) pattern.size();
        vector<int>lps = vector<int>(m);

        int len = 0;
        lps[0] = 0;
        int index = 1;
        while (index < m) {
            if (pattern[index] == pattern[len]) {
                len++;
                lps[index] = len;
                index++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[index] = 0;
                    index++;
                }
            }
        }
        return lps;
    }

    vector<int> searchPattern(string& txt, string& pattern, vector<int>& lps) {
        int m = (int) pattern.size();
        int n = (int) txt.size();
        vector<int> res;

        int i = 0; // index for txt
        int j = 0; // index for pattern
        while (i < n) {
            if (pattern[j] == txt[i]) {
                j++;
                i++;
            }

            if (j == m) {
                res.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && pattern[j] != txt[i]) {
                if (j != 0) j = lps[j - 1];
                else i = i + 1;
            }
        }
        return res;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> alps = computeLPS(a);
        vector<int> blps = computeLPS(b);
        vector<int> as = searchPattern(s, a, alps);
        vector<int> bs = searchPattern(s, b, blps);
        vector<int> ans;
        int j = 0;
        for (auto &idx: as) {
            while (j < bs.size() && idx - bs[j] > k) {
                j++;
            }
            if (j < bs.size() && abs(bs[j] - idx) <= k) {
                ans.push_back(idx);
            }
        };
        return ans;
    }
};
