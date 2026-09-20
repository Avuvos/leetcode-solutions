class Solution {
public:
    int kthDigit(long long k) {
        if (k <= 9) {
            return k;
        }
        long long ten_pow = 1, dig_cnt = 1;
        while (true) {
            long long cur_dig_sum = 9 * dig_cnt * ten_pow;
            if (k <= cur_dig_sum) {
                break;
            }
            k -= cur_dig_sum;
            ten_pow *= 10;
            dig_cnt++;
        }
        k--;
        long long digits = 10 * dig_cnt;
        long long block_num = k / digits;
        long long block_offset = k % digits;

        long long num_in_block = block_offset / dig_cnt;
        long long dig_offset = block_offset % dig_cnt;

        long long block = ten_pow / 10 + block_num;
        long long num = 10 * block + ((block & 1) ? (9 - num_in_block) : num_in_block);
        string num_st = to_string(num);
        int ans = num_st[dig_offset] - '0';
        return ans;
    }
};
