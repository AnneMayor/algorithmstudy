import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main_2693 {
    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= T; tc++) {
            ArrayList<Integer> nums = new ArrayList<>();
            String sNum = br.readLine();
            String iNums [] = sNum.split(" ");
            for(int i = 0; i < 10; i++) {
                nums.add(Integer.parseInt(iNums[i]));
            }

            Collections.sort(nums, Collections.reverseOrder());

            System.out.println(nums.get(2));
        }

        br.close();

    }
}
