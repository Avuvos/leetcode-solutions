class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        bool m1 = start[0] % 2 == target[0] % 2;
        bool m2 = start[1] % 2 == target[1] % 2;
        return (m1 && m2) || (!m1 && !m2);
    }
};
