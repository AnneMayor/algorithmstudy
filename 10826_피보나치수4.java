import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main_10826 {

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        BigInteger [] fibo = new BigInteger[n+3];
        BigInteger fibo0 = new BigInteger("0000000000000000000000000000000");
        BigInteger fibo1 = new BigInteger("0000000000000000000000000000000");
        BigInteger fibo2 = new BigInteger("0000000000000000000000000000000");
        fibo[0] = fibo0.add(BigInteger.ZERO);
        fibo[1] = fibo1.add(BigInteger.ONE);
        fibo[2] = fibo2.add(BigInteger.ONE);

        for(int i = 2; i <= n; i++) {
            fibo1 = fibo[i-1];
            fibo2 = fibo[i-2];
            fibo0 = fibo1.add(fibo2);
            fibo[i] = fibo0;
        }

        System.out.println(fibo[n].toString());
        
    } 
    
}
