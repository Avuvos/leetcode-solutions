class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        if (firstList.length == 0 || secondList.length == 0) return new int [][]{};
        List<int[]> res = new ArrayList<>();
        int a = 0;
        int b = 0;
        while (a < firstList.length && b < secondList.length) {
            int start = Math.max(firstList[a][0], secondList[b][0]);
            int end = Math.min(firstList[a][1], secondList[b][1]);
            if (start <= end) {
                res.add(new int[]{start, end});
            }
            if (firstList[a][1] < secondList[b][1]) {
                a++;
            }
            else {
                b++;
            }
        }
        return res.toArray(new int[0][]);
    }
}
