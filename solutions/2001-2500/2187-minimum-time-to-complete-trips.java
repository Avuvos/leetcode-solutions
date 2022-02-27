class Solution {
    public long minimumTime(int[] time, int totalTrips) {
        long res = 0;
        long low = 1, high = 100000000000000L;
        
        while (low < high) {
            long mid = low + (high - low) / 2;
            long sum = sumTrips(time, mid); 
            if (sum < totalTrips) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
    
    public long sumTrips(int [] time, long t) {
        long sum = 0;
        for (int i = 0; i < time.length; i++) {
            sum += (t / time[i]);
        }
        return sum;
    }
}
