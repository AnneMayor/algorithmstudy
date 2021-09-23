import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Atcoder_Beginner_Contest_217_C {
    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String [] ps = br.readLine().split(" ");
        int [] p = new int[n];
        for(int i = 0; i < n; i++) {
            p[i] = Integer.parseInt(ps[i]);
        }

        int [] q = new int[n];

        for(int i = 0; i < n; i++) {
            q[p[i]-1] = i+1;
        }

        for(int num : q) {System.out.print(num + " ");}
        System.out.println();
    }
}
