import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Atcoder_Beginner_Contest_218_B {

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] stArr = br.readLine().split(" ");

        for(String alpha : stArr) {
            int alphaI = 97 + Integer.parseInt(alpha) - 1;
            System.out.print(Character.toLowerCase((char) alphaI));
        }
        System.out.println();
    }
    
}
