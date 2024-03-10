class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int s = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.rbegin(), capacity.rend());
        int ans = 0;
        for (int i = 0; i < capacity.size(); i++) {
            ans++;
            s -= capacity[i];
            if (s <= 0) break;
        }
        return ans;
    }
};
