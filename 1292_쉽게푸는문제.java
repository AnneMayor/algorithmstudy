import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_1292 {
    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nums = br.readLine().split(" ");
        int a = Integer.parseInt(nums[0]);
        int b = Integer.parseInt(nums[1]);
        
        System.out.println(getTotal(b) - getTotal(a-1));
        br.close();
    }

    public static int getTotal(int num) {
        int stNum = 0;
        int ans = 0;
        for(int start = 0; ;start++) {
            int position = start * (start - 1) / 2;
            if(position > num) {
                stNum = start - 1;
                break;
            }
        }

        for(int i = 1; i < stNum; i++) {
            ans += i * i;
        }

        ans += stNum * (num - (stNum * (stNum - 1)) / 2);

        return ans;
    }
}
