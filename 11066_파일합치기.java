import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 11066_파일합치기 {

    public static void main(String...args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        // Time: O(N^3) | Space: O(N^2)
        // for(int tc = 1; tc <= t; tc++) {
        //     int n = Integer.parseInt(br.readLine());
        //     String [] nums = br.readLine().split(" ");
        //     int [] novels = new int[n+1];
        //     for(int i = 1; i <= n; i++) {
        //         novels[i] = Integer.parseInt(nums[i-1]);
        //     }

        //     int [] sum = new int[n+1];
        //     for(int i = 1; i <= n; i++) {
        //         sum[i] = sum[i-1] + novels[i];
        //     }

        //     int [][] dp = new int[n+1][n+1];

        //     for(int k = 1; k < n; k++) {
        //         for(int s = 1; s + k <= n; s++) {
        //             int e = s + k;

        //             dp[s][e] = Integer.MAX_VALUE;

        //             for(int mid = s; mid < e; mid++) {
        //                 dp[s][e] = Math.min(dp[s][e], dp[s][mid] + dp[mid+1][e] + sum[e] - sum[s-1]);
        //             }
        //         }
        //     }

        //     System.out.println(dp[1][n]);
        // }

        // Time: O(N^2) | Space: O(N^2)
        for(int tc = 1; tc <= t; tc++) {

            int n = Integer.parseInt(br.readLine());

            String [] nums = br.readLine().split(" ");
            int [] novels = new int[n+1];

            for(int i = 1; i <= n; i++) {
                novels[i] = Integer.parseInt(nums[i-1]);
            }

            int [] psum = new int[n+1];
            int [][] points = new int[n+1][n+1];
            for(int i = 1; i <= n; i++) {
                psum[i] = psum[i-1] + novels[i];
                points[i-1][i] = i;
            }

            int [][] dp = new int[n+1][n+1];
            for(int d = 2; d <= n; d++) {
                for(int s = 0; s + d <= n; s++) {
                    int e = s + d;

                    dp[s][e] = Integer.MAX_VALUE;
                    for(int mid = points[s][e-1]; mid <= points[s+1][e]; mid++) {
                        int value = dp[s][mid] + dp[mid][e] + psum[e] - psum[s];
                        if(dp[s][e] > value) {
                            dp[s][e] = value;
                            points[s][e] = mid;
                        }
                    }
                }
            }

            System.out.println(dp[0][n]);
        }

        
    }
}