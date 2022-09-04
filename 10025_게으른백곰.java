import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 10025_게으른백곰 {

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String nk = br.readLine();
        int n = Integer.parseInt(nk.split(" ")[0]);
        int k = Integer.parseInt(nk.split(" ")[1]);

        int [] point = new int[1000005];
        for(int i = 0; i < n; i++) {
            String gx = br.readLine();
            int g = Integer.parseInt(gx.split(" ")[0]);
            int x = Integer.parseInt(gx.split(" ")[1]);
            point[x] = g;
        }

        int ans = 0;
        int sum = 0;
        k = 2 * k + 1;
        for(int x = 0; x <= 1000000; x++) {
            if(x >= k) sum -= point[x - k];
            sum += point[x];
            ans = Math.max(ans, sum);
            // System.out.println("x: " + x + " , sum: " + sum);
        }

        System.out.println(ans);
    }
    
}
