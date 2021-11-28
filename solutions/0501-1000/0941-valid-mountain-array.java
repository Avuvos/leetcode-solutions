class Solution {
    public boolean validMountainArray(int[] arr) {
        int idx = 1;
        boolean foundInc = false;
        boolean foundDec = false;
        while (idx < arr.length && arr[idx] > arr[idx - 1]) {
            foundInc = true;
            idx++;
        }
        while (idx < arr.length && arr[idx] < arr[idx - 1]) {
            foundDec = true;
            idx++;
        }
        return arr.length >= 3 && foundInc && foundDec && idx >= arr.length;
    }
}
