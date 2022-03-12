import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    private static final int INF = 999999999;
    private static int isAllVisited;
    public static void main(String...args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int [][] map = new int[n][n];

        for(int i = 0; i < n; i++) {
            String [] strDist = br.readLine().split(" ");
            for(int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(strDist[j]);
            }
        }

        isAllVisited = (1<<n) - 1;
        int [][] dp = new int[n][isAllVisited];

        for(int i = 0; i < n; i++) {
            Arrays.fill(dp[i], INF);
        }
        
        System.out.println(tsp(dp, map, 0, 1, n));
    }

    public static int tsp(int [][] dp, int [][] map, int current, int isVisited, int n) {
        if(isVisited == isAllVisited) {
            if(map[current][0] == 0) return INF;
            return map[current][0];
        }

        if(dp[current][isVisited] != INF) return dp[current][isVisited];

        for(int i = 0; i < n; i++) {
            int next = isVisited | (1 << i);

            if(map[current][i] == 0 || (isVisited & (1 << i)) != 0) continue;

            dp[current][isVisited] = Math.min(dp[current][isVisited], tsp(dp, map, i, next, n) + map[current][i]);
        }

        return dp[current][isVisited];
    }
    
}