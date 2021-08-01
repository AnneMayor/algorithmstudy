import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_1475 {
    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String num = br.readLine();

        int isPlateIn [] = new int[10];

        for(int i = 0; i < num.length(); i++) {
            isPlateIn[num.charAt(i) - '0']++;
        }

        int ans = -1;
        for(int i = 0; i < 10; i++) {
            if(i == 6 || i == 9) continue;
            ans = Math.max(ans, isPlateIn[i]);
        }

        int sixAndNine = (isPlateIn[6] + isPlateIn[9]) % 2 == 1 ? (isPlateIn[6]+isPlateIn[9]) / 2 + 1 : (isPlateIn[6] + isPlateIn[9]) / 2;
        ans = Math.max(ans, sixAndNine);

        System.out.println(ans);
        br.close();
    } 
}
