class Solution {
    public int findTheWinner(int n, int k) {
        List<Integer> game = new ArrayList<>();
        for (int i=1; i<n+1; i++) {
            game.add(i); //add the players to the game
        }
        int pos = 0;
        while (game.size() > 1) {
            //System.out.println(game.toString());
            pos = (pos + k - 1) % game.size();
            game.remove(pos); //remove the player
        }
        return game.get(0); //return the last player
    }
}
