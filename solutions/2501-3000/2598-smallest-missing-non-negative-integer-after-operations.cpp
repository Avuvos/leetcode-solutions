class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int mex = 0;
        //we want to check if there is x such that x - 5*k == target for some k in Z.
        //x == target + 5k which means
        //x - target == 0 mod 5.
        unordered_multiset<int> s;
        int n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            int x = nums[i] % value;
            if (x < 0) x += value;
            s.insert(x);
        }
        while (!s.empty()) {
            auto it = s.find(mex % value);
            if (it == s.end()) return mex;
            s.erase(it);
            mex++;
        }
        return mex;
    }
};
