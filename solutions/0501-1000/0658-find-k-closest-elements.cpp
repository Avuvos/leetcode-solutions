class Solution {
public:
    int dist(vector<int>& arr, int a, int b) {
        return abs(a - b);
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int left = it - arr.begin() - 1;
        int right = it - arr.begin();
        vector<int> result;
        while (k--) {
            if (left >= 0 && right < arr.size()) {
                int dist_left = dist(arr, x, arr[left]);
                int dist_right = dist(arr, x, arr[right]);
                if (dist_left < dist_right || (dist_left == dist_right && arr[left] < arr[right])) {
                    result.push_back(arr[left]);
                    left--;
                }
                else {
                    result.push_back(arr[right]);
                    right++;
                }
            }
            else if (left >= 0) {
                result.push_back(arr[left]);
                left--;
            }
            else {
                result.push_back(arr[right]);
                right++;
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};
