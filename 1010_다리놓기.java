import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_1010 {

    public static int combDp[][];
    
    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= T; tc++) {
            String [] nm = br.readLine().split(" ");
            int n = Integer.parseInt(nm[0]);
            int m = Integer.parseInt(nm[1]);

            combDp = new int[m+1][m+1];
            combDp[0][0] = 1;

            for(int i = 1; i <= m; i++) {
                for(int j = 0; j <= i; j++) {
                    if(j == 0 || j == i) {
                        combDp[i][j] = 1;
                    } else {
                        combDp[i][j] = combDp[i-1][j-1] + combDp[i-1][j];
                    }
                }
            }

            System.out.println(combDp[m][n]);
        }

        br.close();
    } 
}
