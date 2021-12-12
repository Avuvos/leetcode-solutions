class Solution {
    public int minimumRefill(int[] plants, int capacityA, int capacityB) {
        int n = plants.length;
        int left = 0, right = n - 1;
        int currA = capacityA, currB = capacityB;
        int res = 0;
        while (left <= right) {
            if (left != right) {
                if (plants[left] > currA) {
                    currA = capacityA;
                    res++;
                }
                if (plants[right] > currB) {
                    currB = capacityB;
                    res++;
                }
                currA -= plants[left];
                left++;
                currB -= plants[right];
                right--;
            }
            else {
                if (currA >= plants[left] || currB >= plants[left]) break;
                else res++;
                left++;
                right--;
            }
         }
        return res;
    }
}
