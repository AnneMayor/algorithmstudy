public class LeetCode_CountNumberOfTexts {

    private final int MOD = (int) Math.pow(10, 9) + 7;

    public int countTexts(String pressedKeys) {
        int n = pressedKeys.length();

        int [] dp = new int[n+1];

        dp[0] = 1;

        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i-1];

            int currentChar = pressedKeys.charAt(i-1);

            if(i >= 2) {
                if(currentChar == pressedKeys.charAt(i-2)) {
                    dp[i] = (dp[i] + dp[i-2]) % MOD;
                    if(i >= 3) {
                        if(currentChar == pressedKeys.charAt(i-3)) {
                            dp[i] = (dp[i] + dp[i-3]) % MOD;
                            if((currentChar == '7' || currentChar == '9') && i >= 4) {
                                if(currentChar == pressedKeys.charAt(i-4)) dp[i] = (dp[i] + dp[i-4]) % MOD;
                            }
                        }
                    }
                }
            }
        }

        return dp[n];
    }
}
