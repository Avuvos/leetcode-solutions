class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = (int) nums.size(), m = (int) changeIndices.size();
        if (m < n) {
            return -1;
        }
        auto ok = [&](int len) -> bool {
            map<int, int> last;
            auto a = nums;
            for (int i = 0; i < len; i++) {
                last[changeIndices[i] - 1] = i;
            }
            for (int i = 0; i < n; i++) {
                if (last.find(i) == last.end()) {
                    return false;
                }
            }
            int ops = 0;
            vector<bool> marked(n, false);
            for (int i = 0; i < len; i++) {
                ops++;
                int idx = changeIndices[i] - 1;
                if (last[idx] == i) {
                    if (ops < a[idx] + 1) {
                        return false;
                    }
                    ops -= (a[idx] + 1);
                    marked[idx] = true;
                }
            }
            for (int i = 0; i < n; i++) {
                if (!marked[i]) {
                    return false;
                }
            }
            return true;
        };


        int left = 1, right = m, ans = -1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (ok(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
