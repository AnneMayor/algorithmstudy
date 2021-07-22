import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Main_5576 {

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Integer [] wUniv = new Integer[10];
        Integer [] kUniv = new Integer[10];

        for(int i = 0; i < 10; i++) {
            wUniv[i] = Integer.parseInt(br.readLine());
        }

        for(int i = 0 ; i < 10; i++) {
            kUniv[i] = Integer.parseInt(br.readLine());
        }

        int wUnivScore = 0, kUnivScore = 0;

        Collections.sort(Arrays.asList(wUniv), Collections.reverseOrder());
        Collections.sort(Arrays.asList(kUniv), Collections.reverseOrder());

        for(int i = 0 ; i < 3; i++) {
            wUnivScore += wUniv[i];
            kUnivScore += kUniv[i];
        }
        
        bw.write(wUnivScore + " " + kUnivScore + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
    
}
