public class Solution {
    public int superEggDrop(int k, int n) {
        int[] dp = new int[k+1];
        int numOfMoves = 0;

        for (; dp[k] < n; numOfMoves++) {
            for (int i = k; i > 0; i-- ) {
                dp[i] += dp[i-1] + 1;
            }
        }

        return numOfMoves;
    }
}