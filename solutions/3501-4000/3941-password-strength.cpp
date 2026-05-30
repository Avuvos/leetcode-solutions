class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> low, up, dig, spec;
        for (auto &c: password) {
            if (islower(c)) {
                low.insert(c);
            } else if (isupper(c)) {
                up.insert(c);
            } else if (isdigit(c)) {
                dig.insert(c);
            } else {
                spec.insert(c);
            }
        }
        return low.size() + 2 * up.size() + 3 * dig.size() + 5 * spec.size();
    }
};
