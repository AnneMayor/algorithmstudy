import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

public class Atcoder_Beginner_Contest_217_A {
    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] words = br.readLine().split(" ");
        String s1 = words[0];
        String s2 = words[1];

        Arrays.sort(words);

        if(s1.equals(words[0])) System.out.println("Yes");
        else System.out.println("No");
    }
}