import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main_2839 {

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int [] dp = new int[n+5];
        Arrays.fill(dp, 100000);
        
        dp[3] = 1;
        dp[5] = 1;
        for(int i = 6; i <= n; i++) {
            dp[i] = Math.min(dp[i], Math.min(dp[3] + dp[i-3], dp[5] + dp[i-5]));
        }

        if(dp[n] >= 10000) {
            System.out.println(-1);
        } else {
            System.out.println(dp[n]);
        }
        br.close();
    }
    
}
