class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        vector<int> res;
        unordered_map<int, int> count;
        for (auto num: changed)
            count[num]++;
            
        for (auto num: changed) {
            if (count[num] == 0)
                continue;
            else if (count[2*num] > 0) {
                res.push_back(num);
                count[2*num]--;
                count[num]--;
            }
            else
                return vector<int>{};
        }
        return res.size() * 2 == changed.size() ? res : vector<int>{};
        
    }
};
