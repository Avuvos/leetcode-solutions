class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int cnt = 0, sum = 0, left = 0;
        for (int right=0; right<arr.length; right++) {
            sum += arr[right]; //add to the running sum
            if (right - left + 1 == k) { //if window size is k
                if (sum / k >= threshold) { //check the condition
                    cnt++; //increment the count
                }
                sum -= arr[left]; //substract the left element
                left++; //shift the window by one
            }
        }
        return cnt;
    }
}
