import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;

public class Atcoder_Beginner_Contest_217_D {

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] lq = br.readLine().split(" ");
        int l = Integer.parseInt(lq[0]);
        int q = Integer.parseInt(lq[1]);

        TreeSet<Integer> sts = new TreeSet<>();
        sts.add(l);
        sts.add(0);

        for(int i = 0; i < q; i++) {

            String [] cx = br.readLine().split(" ");
            int c = Integer.parseInt(cx[0]);
            int x = Integer.parseInt(cx[1]);

            switch(c) {
                case 1:
                sts.add(x);
                break;

                case 2:
                int prev = sts.floor(x);
                int next = sts.ceiling(x);
                System.out.println(next - prev);
                break;
            }
        }
    }
}
