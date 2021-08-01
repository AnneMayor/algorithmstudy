import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main_1977 {

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        double m, n;
        m = Double.parseDouble(br.readLine());
        n = Integer.parseInt(br.readLine());

        int start = (int) Math.sqrt(m);
        start = (start * start < m ? start + 1 : start);
        int totalSum = 0;
        for(int i = start; i * i <= n; i++) {
            totalSum += i * i;
        }

        if(totalSum > 0) {
            System.out.println(totalSum);
            System.out.println(start*start);
        } else {
            System.out.println("-1");
        }

        br.close();
    }

}