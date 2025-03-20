class Solution {
public:
    int maxDistance(string s, int k) {
        int best = 0, dx = 0, dy = 0;
        for (int i = 0; i < s.size(); i++) {
            dx += s[i] == 'E' ? 1 : s[i] == 'W' ? -1 : 0;
            dy += s[i] == 'N' ? 1 : s[i] == 'S' ? -1 : 0;
            best = max(best, min(abs(dx) + abs(dy) + 2 * k ,i + 1));
        }
        return best;
    }
};
