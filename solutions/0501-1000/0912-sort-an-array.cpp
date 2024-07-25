class Solution {
public:
    
    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> c;
        int n = (int) a.size(), m = (int) b.size();
        int i = 0, j = 0;
        while (i < n || j < m) {
            if (i < n &&  (j >= m || a[i] < b[j])) {
                c.push_back(a[i++]);
            } else {
                c.push_back(b[j++]);
            }
        }
        return c;
    }
    
    vector<int> mergesort(int left, int right, vector<int>& nums) {
        if (left > right) {
            return {};
        }
        if (left == right) {
            return {nums[left]};
        }
        int mid = (left + right) / 2;
        vector<int> L = mergesort(left, mid, nums);
        vector<int> R = mergesort(mid + 1, right, nums);
        return merge(L, R);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        return mergesort(0, nums.size() - 1, nums);
    }
};
