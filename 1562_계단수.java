import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static long [][][] dp;
    public static void main(String...args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        dp = new long[n+1][10][(1<<10)];

        long mod = 1_000_000_000l;

        for(int i = 1; i < 10; i++) {
            dp[1][i][(1 << i)] = 1;
        }

        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < 10; j++) {
                for(int k = 1; k < (1 << 10); k++) {
                    if(j - 1 >= 0) {
                        dp[i][j][k | (1 << j)] += dp[i-1][j-1][k] ;
                    }

                    if(j + 1 <= 9) {
                         dp[i][j][k | (1 << j)] += dp[i-1][j+1][k];
                    }

                    dp[i][j][k | (1 << j)] %= mod;
                }
            }
        }

        long ans = 0l;
        for(int i = 0; i < 10; i++) {
            ans += dp[n][i][(1 << 10) - 1];
            ans %= mod;
        }

        System.out.println(ans);
    }
    
}
