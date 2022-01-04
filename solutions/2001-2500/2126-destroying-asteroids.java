class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        long expandingMass = mass;
        Arrays.sort(asteroids);
        for (int ast: asteroids) {
            if (expandingMass >= ast) {
                expandingMass += ast;
            }
            else {
                return false;
            }
        }
        return true;
    }
}
