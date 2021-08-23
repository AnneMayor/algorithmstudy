import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main_12180 {

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= T; tc++) {
            String [] rc = br.readLine().split(" ");
            int r = Integer.parseInt(rc[0]);
            int c = Integer.parseInt(rc[1]);

            Long [][] dp = new Long[r+1][c+1];

            for(int i = 0; i < r; i++) {
                Arrays.fill(dp[i], 0L);
            }

            for(int i = 0 ; i < r; i++) {
                dp[i][0] = 1L;
            }

            for(int i = 0; i < c; i++) {
                dp[r-1][i] = 1L;
            }

            for(int i = r-2; i >= 0; i--) {
                for(int j = 1; j < c; j++) {
                    dp[i][j] = dp[i][j-1] + dp[i+1][j];
                }
            }

            // for(int i = 0; i < r; i++) {
            //     for(int j = 0; j < c; j++) {
            //         System.out.print(dp[i][j] + " ");
            //     }
            //     System.out.println();
            // }

            System.out.println("Case #" + tc + ": " + dp[0][c-1]);
        }
    }
}