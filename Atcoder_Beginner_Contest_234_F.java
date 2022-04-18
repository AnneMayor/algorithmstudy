import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Atcoder_Beginner_Contest_234_F {
    public static void main(String...args) throws IOException {
        final int MAX = 5005;
        final int MOD = 998244353;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String s = br.readLine();

        int n = s.length();

        long [][] dp = new long[MAX][MAX];
        long [][] comb = new long[MAX][MAX];
        int [] cntOfAlphabets = new int[27];

        for(int i = 0; i < n; i++) {
            cntOfAlphabets[s.charAt(i) - 'a'+1]++;
        }

        for(int i = 0; i < MAX; i++) {
            comb[i][0] = 1; comb[i][i] = 1;
            for(int j = 1; j < i; j++) {
                comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
            }
        }

        dp[0][0] = 1;

        for(int i = 1; i <= 26; i++) {
            for(int j = 0; j <= n; j++) {
                for(int k = 0; k <= Math.min(j, cntOfAlphabets[i]); k++) {
                    long res = (dp[i-1][j-k] * comb[j][k]) % MOD;
                    dp[i][j] = (dp[i][j] + res) % MOD;
                }
            }
        }

        long ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = (ans + dp[26][i]) % MOD;
        }

        System.out.println(ans);
    }
    
}