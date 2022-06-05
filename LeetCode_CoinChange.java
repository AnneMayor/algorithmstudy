import java.util.Arrays;

public class LeetCode_CoinChange {
    public int coinChange(int[] coins, int amount) {
        int [] dp = new int[amount+1];
        
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        for(int coin : coins) {
            if(coin <= amount) {
                dp[coin] = 1;
            }
        }

        for(int i = 1; i <= amount; i++) {
            for(int coin : coins) {
                if(i - coin >= 0) {
                    if(dp[i-coin] != Integer.MAX_VALUE && dp[coin] != Integer.MAX_VALUE)
                        dp[i] = Math.min(dp[i], dp[coin] + dp[i-coin]);
                }
            }
        }
        
        if(dp[amount] == Integer.MAX_VALUE) dp[amount] = -1;

        return dp[amount];
    }
}
