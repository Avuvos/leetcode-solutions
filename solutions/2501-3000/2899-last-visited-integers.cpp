class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> nums;
        vector<int> ans;
        int streak = 0;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == "prev") {
                streak++;
                int m = (int) nums.size();
                int index = m - streak;
                if (index >= 0) {
                    ans.push_back(nums[index]);
                } else {
                    ans.push_back(-1);
                }
            } else {
                nums.push_back(stoi(words[i]));
                streak = 0;
            }
        }
        return ans;
    }
};
