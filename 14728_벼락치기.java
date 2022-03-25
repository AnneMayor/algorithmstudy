import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] nt = br.readLine().split(" ");

        int n = Integer.parseInt(nt[0]), t = Integer.parseInt(nt[1]);

        int [] studyTime = new int[n+1];
        int [] score = new int[n+1];

        for(int i = 1; i <= n; i++) {
            String [] ks = br.readLine().split(" ");
            studyTime[i] = Integer.parseInt(ks[0]);
            score[i] = Integer.parseInt(ks[1]);
        }

        int [][] dp = new int[n+1][t+1];
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= t; j++) {
                if(studyTime[i] <= j) {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-studyTime[i]] + score[i]);
                } else dp[i][j] = dp[i-1][j];
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= t; j++) {
                ans = Math.max(ans, dp[i][j]);
            }
        }

        System.out.println(ans);
    }
    
}
