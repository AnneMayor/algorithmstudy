import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class 7567_그릇 {
    public static void main(String...args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String bowls = br.readLine();
        int ans = 10;
        for(int i = 1; i < bowls.length(); i++) {
            if(bowls.charAt(i) == bowls.charAt(i-1)) ans += 5;
            else ans += 10;
        }

        System.out.println(ans);
    }
}
