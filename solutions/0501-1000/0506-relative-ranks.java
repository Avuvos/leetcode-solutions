class Solution {
public String[] findRelativeRanks(int[] score) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> score[b] - score[a]);
        String[] res = new String[score.length];
        for (int i = 0; i < score.length; i++) {
            maxHeap.offer(i);
        }
        for (int i = 0; i < score.length; i++) {
            int idx = maxHeap.poll();
            if (i == 0) {
                res[idx] = "Gold Medal";
            }
            else if (i == 1) {
                res[idx] = "Silver Medal";
            }
            else if (i == 2) {
                res[idx] = "Bronze Medal";
            }
            else {
                res[idx] = ""+(i+1);
            }
        }
        return res;
    }
}
