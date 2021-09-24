import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Atcoder_Beginner_Contest_218_A {

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String forecast = br.readLine();

        char weather = forecast.charAt(n-1);
        if(weather == 'o') {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
    
}
