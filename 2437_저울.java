import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

public class Main {
    public static boolean isVisited [];
    public static Integer weights [];

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        weights = new Integer[n];
        String weight = br.readLine();
        String sWeight[] = weight.split(" ");
        for(int i = 0; i < n; i++) {
            weights[i] = Integer.parseInt(sWeight[i]);
        }

        Collections.sort(Arrays.asList(weights));

        long ans = 1;
        for(int i = 0; i < n; i++) {
            if(ans < weights[i]) break;
            ans += weights[i];
        }

        System.out.println(ans);
    }
}
