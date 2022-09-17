class Solution {
public:

    void update_bits(vector<int>& cnt, int num, int sign) {
        for (int i = 0; i < 32; ++i) {
            cnt[i] += sign * ((num >> i) & 1);
        }
    }

    long long convert(vector<int>& cnt) {
        long long res = 0;
        long long shift = 1;
        for (int i = 0; i < cnt.size(); ++i) {
            res += (cnt[i] > 0 ? 1 : 0) * shift;
            shift *= 2;
        }
        return res;
    }

    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        vector<int> count(32, 0);
        update_bits(count, nums[n - 1], 1);
        int best_or = nums[n - 1];
        ans[n - 1] = 1;
        int right = n - 1;

        for (int index = n - 2; index >= 0 ; index--) {
            int num = nums[index];
            best_or |= num;
            update_bits(count, num, 1);
            while (convert(count) == best_or && right > index) {
                update_bits(count, nums[right], -1);
                right--;
            }
            if (convert(count) != best_or) {
                right++;
                update_bits(count, nums[right], 1);
            }
            ans[index] = right - index + 1;
        }
        return ans;
    }
};
