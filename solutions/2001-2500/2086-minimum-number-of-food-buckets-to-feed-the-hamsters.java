class Solution {
    public int minimumBuckets(String street) {
        int res = 0;
        //lets apply the greedy algo
        int idx = 0;
        boolean prevBucket = false;
        while (idx < street.length()) {
            if (street.charAt(idx) == 'H') {
                if (prevBucket) {
                    idx++;
                    prevBucket = false;
                }
                else if (idx + 1 < street.length() && street.charAt(idx + 1) == '.') {
                    res++;
                    idx += 2;
                    prevBucket = true;
                }
                else if (idx - 1 >= 0 && street.charAt(idx - 1) == '.') {
                    idx++;
                    res++;
                    prevBucket = false;
                }
                else {
                    return -1;
                }
            }
            else {
                idx++;
                prevBucket = false;
            }
        }
        return res;
    }
}
