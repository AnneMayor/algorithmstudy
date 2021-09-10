import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static int [][] map;
    public static int [][] d;

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] ve = br.readLine().split(" ");
        int v = Integer.parseInt(ve[0]);
        int e = Integer.parseInt(ve[1]);

        map = new int[405][405];
        d = new int[405][405];

        for(int i = 0; i < e; i++) {
            String [] abp = br.readLine().split(" ");
            int a = Integer.parseInt(abp[0]);
            int b = Integer.parseInt(abp[1]);
            int p = Integer.parseInt(abp[2]);
            map[a][b] = p;
        }

        // 최소거리 구하기(플로이드 와샬)
        floydWarshell(v);

        int ans = 1000000;

        // for(int i = 1; i <= v; i++) {
        //     for(int j = 1; j <= v; j++) {
        //         System.out.print(d[i][j] + " ");
        //     }
        //     System.out.println();
        // }
        // System.out.println();

        for(int i = 1; i <= v; i++) {
            for(int j = 1; j <= v; j++) {
                if(i == j) continue;
                if(d[i][j] != 1000000 && d[j][i] != 1000000) {
                    ans = Math.min(ans, d[i][j] + d[j][i]);
                }
            }
        }

        if(ans >= 1000000) {
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }
    }

    public static void floydWarshell(int v) {

        for(int i = 1; i <= 400; i++) {
            for(int j = 1; j <= 400; j++) {
                if(map[i][j] == 0) d[i][j] = 1000000;
                else d[i][j] = map[i][j];
            }
        }

        for(int k = 1; k <= v; k++) {
            for(int i = 1; i <= v; i++) {
                for(int j = 1; j <= v; j++) {
                    if(d[i][k] + d[k][j] < d[i][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }
    }
    
}
