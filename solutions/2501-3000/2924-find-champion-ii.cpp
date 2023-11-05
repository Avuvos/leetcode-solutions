class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> deg(n, 0);
        for (auto e: edges) {
            deg[e[1]]++;
        }
        vector<int> cand;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                cand.push_back(i);
            }
        }
        return (cand.size() == 1 ? cand[0] : -1);
    }
};
