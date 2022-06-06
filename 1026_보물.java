import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

public class 1026_보물 {

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        Integer a [] = new Integer[n];
        Integer b [] = new Integer[n];

        String sa = br.readLine();
        String saa[] = sa.split(" ");
        String sb = br.readLine();
        String sbb[] = sb.split(" ");
        
        for(int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(saa[i]+"");
        }

        for(int i = 0; i < n; i++) {
            b[i] = Integer.parseInt(sbb[i]+"");
        }
        
        Collections.sort(Arrays.asList(a), Collections.reverseOrder());
        Collections.sort(Arrays.asList(b));

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += a[i] * b[i];
        }

        System.out.println(ans);
    }
    
}
