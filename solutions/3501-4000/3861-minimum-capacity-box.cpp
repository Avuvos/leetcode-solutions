class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int best = -1;
        for (int i = capacity.size() - 1; i >= 0; i--) {
            if (capacity[i] >= itemSize && (best == -1 || capacity[best] >= capacity[i])) {
                best = i;
            }
        }
        return best;
    }
};
