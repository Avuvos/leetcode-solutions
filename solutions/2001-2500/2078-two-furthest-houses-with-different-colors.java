class Solution {
    public int maxDistance(int[] colors) {
        int best = 0;
        int color = colors[0];
        int idx = 0;
        for (int i = 1; i < colors.length; i++) {
            if (colors[i] != color) {
                best = Math.max(best, i - idx);
            }
        }
        color = colors[colors.length - 1];
        idx = colors.length - 1;
        for (int i = colors.length - 2; i >= 0; i--) {
            if (colors[i] != color) {
                best = Math.max(best, idx - i);
            }
        }
        return best;
    }
}
