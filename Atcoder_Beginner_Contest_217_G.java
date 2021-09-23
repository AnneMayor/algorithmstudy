import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Atcoder_Beginner_Contest_217_G {

    public static Long [][] modulo;
    public static final int MODULO = 998244353;

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);

        modulo = new Long[n+1][n+1];
        for(Long [] arr : modulo) {
            Arrays.fill(arr, 0L);
        }

        modulo[0][0] = 1L;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                modulo[i][j] = (modulo[i-1][j-1] + modulo[i-1][j] * (j-(i-1) / m)) % MODULO;
            }
        }

        for(int i = 1; i <= n; i++) {
            System.out.println(modulo[n][i]);
        }
    }
}
