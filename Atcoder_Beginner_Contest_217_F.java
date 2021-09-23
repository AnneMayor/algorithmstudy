import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Atcoder_Beginner_Contest_217_F {

    public static Long [][] dp;
    public static Long [][] nCr;
    public static Long MOD = 998244353L;

    public static void getCombinationNum() {
        nCr = new Long[202][202];
        for(Long [] arr : nCr) {
            Arrays.fill(arr, 1L);
        }

        for(int i = 2; i <= 200; i++) {
            for(int j = 1; j < i; j++) {
                nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
                nCr[i][j] %= MOD;
            }
        }
    }

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);

        ArrayList<ArrayList<Integer> > arr = new ArrayList<>();
        dp = new Long[404][404];

        for(Long [] ar : dp) {
            Arrays.fill(ar, 0L);
        }

        getCombinationNum();

        for(int i = 0; i <= 2*n+2; i++) {
            arr.add(new ArrayList<>());
        }

        for(int i = 0; i < m; i++) {
            String [] ab = br.readLine().split(" ");
            int a = Integer.parseInt(ab[0]);
            int b = Integer.parseInt(ab[1]);
            a--; b--;
            arr.get(a).add(b);
        }

        for(int i = 0; i <= 2*n+2; i++) {
            dp[i][0] = 1L;
        }

        // i: 시작 가능한 index 번호
        for(int i = 2*n-1; i >= 0; i--) {
            // j: 선택 가능한 원소의 개수
            for(int j = 1; j <= (2*n - i + 1) / 2; j++) {
                for(int num : arr.get(i)) {
                    if(((num - i) & 1) != 1)  continue;
                    int index = (num - i + 1) / 2;
                    if(index > j) continue;
                    // System.out.println("i: " + i + " / j: " + j);
                    dp[i][j] += ((dp[i+1][index-1] * dp[i+2*index][j-index])%MOD * nCr[j][index])%MOD;
                    dp[i][j] %= MOD;
                }
            }
        }

        System.out.println(dp[0][n]);
    }
}