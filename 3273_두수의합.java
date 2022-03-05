import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        String [] nums = br.readLine().split(" ");
        int len = nums.length;
        int [] numInt = new int[len];
        for(int i = 0 ; i < len; i++) {
            numInt[i] = Integer.parseInt(nums[i]);
        }

        Arrays.sort(numInt);

        int x = Integer.parseInt(br.readLine());

        int start = 0, end = len-1;
        int res = 0;
        while(start < end) {
            int sum = numInt[start] + numInt[end];
            if(sum > x) {
                end--;
            } else if(sum == x) {
                res++;
                start++;
            } else {
                start++;
            }
        }

        System.out.println(res);
    }
    
}
