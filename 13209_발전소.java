import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main_13209 {

    public static Long [] dp;
    public static boolean [] isBroken;
    public static int [][] expense;

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        expense = new int[n+1][n+1];
        
        isBroken = new boolean[n+1];

        dp = new Long[1 << n];

        for(int i = 0; i < n; i++) {
            String [] exps = br.readLine().split(" ");
            for(int j = 0; j < n; j++) {
                expense[i][j] = Integer.parseInt(exps[j]);
            }
        }

        String status = br.readLine();

        int p = Integer.parseInt(br.readLine());
        int operatingPlant = 0;

        for(int i = 0; i < status.length(); i++) {
            if(status.charAt(i) == 'N') {
                isBroken[i] = true;
            } else {
                operatingPlant |= (1 << i);
            }
        }

        Arrays.fill(dp, -1L);

        Long ans = bitmaskDp(operatingPlant, p, n);
        if(ans == 100000000L) {
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }
    }

    public static Long bitmaskDp(int current, int p, int n) {
        if(bitCount(current) >= p) return 0L;
        if(dp[current] != -1L) return dp[current];

        Long res = 100000000L;

        for(int i = 0; i < n; i++) {
            int isOn = current & (1 << i);
            if(isOn == 0) continue;
            for(int j = 0; j < n; j++) {
                isOn = current & (1 << j);
                if(isOn == 0) {
                    res = Math.min(res, bitmaskDp(current | (1 << j), p, n) + expense[i][j]);
                }
            }
        }


        return dp[current] = res;
    }

    public static int bitCount(int state) {
        int res = 0;
        while(state > 0) {
            res += (state & 1);
            state >>= 1;
        }

        return res;
    }
    
}
