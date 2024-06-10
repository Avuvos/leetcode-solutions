class NumArray {
public:
    int n;
    vector<int> sums;
    NumArray(vector<int>& nums) {
        n = (int) nums.size();
        sums.resize(2 * n, 0);
        for (int i = 0; i < n; i++) {
            sums[i + n] = nums[i];
        }
        for (int i = n - 1; i > 0; i--) {
            sums[i] = sums[i << 1] + sums[i << 1 | 1];
        }
    }
    
    void update(int index, int val) {    
        for (sums[index += n] = val; index > 1; index >>= 1) {
            sums[index >> 1] = sums[index] + sums[index ^ 1];
        }
    }
    
    int sumRange(int left, int right) {
        right++;
        int res = 0;
        for (left += n, right += n; left < right; left >>= 1, right >>= 1) {
            if (left & 1) {
                res += sums[left];
                left++;
            }
            if (right & 1) {
                right--;
                res += sums[right];
            }
        }
        return res;
    }   
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
