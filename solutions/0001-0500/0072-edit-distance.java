class Solution {
    public int minDistance(String word1, String word2) {
        int n = word1.length(), m = word2.length();
        int [][] dp = new int [n + 1][m + 1];
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 && j == 0) { //both words are empty
                    dp[i][j] = 0; //basically saying continue
                }
                else if (i == 0 && j != 0) { //word1 is empty
                    dp[i][j] = j;
                }
                else if (i != 0 && j == 0) { //word2 is empty
                    dp[i][j] = i; 
                }
                else if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int ins = dp[i][j - 1];
                    int del = dp[i - 1][j];
                    int swap = dp[i - 1][j - 1];
                    dp[i][j] = 1 + Math.min(Math.min(ins, del), swap);
                }
            }
        }
        return dp[n][m];
    }
}
