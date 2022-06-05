public class LeetCode_longestCommonSubsequence {

    public int longestCommonSubsequence(String text1, String text2) {
        int tx1Length = text1.length(), tx2Length = text2.length();
        
        int [][] dp = new int[tx1Length+1][tx2Length+1];

        for(int i = 0; i <= tx1Length; i++) {
            for(int j = 0; j <= tx2Length; j++) {
                if(i == 0 || j == 0) continue;

                if(text1.charAt(i-1) == text2.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i][j], Math.max(dp[i-1][j], dp[i][j-1]));
                }
            }
        }

        int ans = 0;
        for(int i = 0; i <= tx2Length; i++) {
            ans = Math.max(ans, dp[tx1Length][i]);
        }
        
        return ans;
    }
    
}
