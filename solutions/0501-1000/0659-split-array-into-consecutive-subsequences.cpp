class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int ,int> counter, ending;
        for (auto a: nums) {
            counter[a]++;
        }
        for (auto a: nums) {
            if (counter[a] == 0) continue;
            counter[a]--;
            if (ending[a - 1] > 0) {
                ending[a - 1]--;
                ending[a]++;
            }
            else if (counter[a + 1] > 0 && counter[a + 2] > 0) {
                counter[a + 1]--;
                counter[a + 2]--;
                ending[a + 2]++;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
