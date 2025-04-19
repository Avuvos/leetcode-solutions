class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        map<int, int> div_to_idx;
        for (int i = 0; i < elements.size(); i++) {
            int x = elements[i];
            if (div_to_idx.contains(x)) continue;
            div_to_idx[x] = i;
        }
        vector<int> assigned;
        for (auto &y: groups) {
            int best_idx = 300000;
            for (int d = 1; d * d <= y; d++) {
                if (y % d == 0) {
                    if (div_to_idx.contains(d)) {
                      best_idx = min(best_idx, div_to_idx[d]);  
                    }
                    if (div_to_idx.contains(y / d)) {
                      best_idx = min(best_idx, div_to_idx[y / d]);  
                    }
                }
            }
            assigned.push_back(best_idx < 300000 ? best_idx : -1);
        }
        return assigned;
    }
};
