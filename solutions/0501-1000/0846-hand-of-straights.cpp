class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        multiset<int> ms(hand.begin(), hand.end());
        while (!ms.empty()) {
            int current = *ms.begin();
            ms.erase(ms.begin());
            int sz = 1;
            while (sz < groupSize) {
                auto it = ms.upper_bound(current);
                if (it == ms.end()) {
                    return false;
                }
                if (*it - current != 1) {
                    return false;
                }
                current = *it;
                ms.erase(it);
                sz++;
            }
        }
        return true;
    }
};
