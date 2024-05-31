/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int* ret = (int*) malloc(2 * sizeof(int));
    int xor = 0;
    for (int i = 0; i < numsSize; i++) {
        xor ^= nums[i];
    }
    int b = 0;
    for (int bit = 0; bit < 30; bit++) {
        if ((xor >> bit) & 1) {
            b = bit;
            break;
        }
    }
    int first_num = 0;
    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] >> b) & 1) {
            first_num ^= nums[i];
        }
    }
    int second_num = first_num ^ xor;
    ret[0] = first_num;
    ret[1] = second_num;
    return ret;
}
