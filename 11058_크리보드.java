import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_11058 {

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        long [] dp = new long[n+5];

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        
        for(int i = 4; i <= n; i++) {
            for(int j = 3; i - j > 0; j++) {
                dp[i] = Math.max(dp[i-1]+1, Math.max(dp[i-j] * (j-1), dp[i]));
            }
        }

        System.out.println(dp[n]);
    }
    
}
