import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Atcoder_Beginner_Contest_217_B {

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] regularContest = {"ABC", "ARC", "AGC", "AHC"};
        String s1 = br.readLine();
        String s2 = br.readLine();
        String s3 = br.readLine();

        HashSet<String> hs = new HashSet<>();
        hs.add(s1);
        hs.add(s2);
        hs.add(s3);

        for(String contest : regularContest) {
            if(!hs.contains(contest)) {
                System.out.println(contest);
            }
        }
    }
    
}
