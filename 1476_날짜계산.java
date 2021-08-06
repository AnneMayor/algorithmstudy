import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_1476 {
    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String esm = br.readLine();
        String [] esmSplit = esm.split(" ");
        int e = Integer.parseInt(esmSplit[0]);
        int s = Integer.parseInt(esmSplit[1]);
        int m = Integer.parseInt(esmSplit[2]);

        int start = 1;

        while(true) {
            // System.out.println(start);
            int eRemain = (start % 15 == 0 ? 15 : (start % 15));
            int sRemain = (start % 28 == 0 ? 28 : (start % 28));
            int mRemain = (start % 19 == 0 ? 19 : (start % 19));

            if(eRemain == e && sRemain == s && mRemain == m) break;

            start++;
        }

        System.out.println(start);

        br.close();
    }
}
