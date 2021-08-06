import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;

public class Main_2108 {

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new java.io.InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer> nums = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());
            nums.add(num);
        }

        double total = 0; int minNum = 0; int maxNum = 0;
        for(int i = 0; i < n; i++) {
            total += nums.get(i);
        }
        System.out.println(Math.round(total/n));
        Collections.sort(nums);

        minNum = nums.get(0); maxNum = nums.get(n-1);
        
        System.out.println(nums.get(n/2));

        HashMap<Integer, Integer> count = new HashMap<>();

        for(int i = 0; i < n; i++) {
            if(!count.containsKey(nums.get(i))) {
                count.put(nums.get(i), 1);
            } else {
                int curCnt = count.get(nums.get(i)) + 1;
                count.put(nums.get(i), curCnt);
            }
        }

        Collections.sort(nums, new Comparator<Integer>(){

            @Override
            public int compare(Integer o1, Integer o2) {
                return count.get(o2) - count.get(o1);
            }
            
        });

        int ans = nums.get(0);
        
        for(int i = 1; i < n; i++) {
            if(count.get(ans) <= count.get(nums.get(i))) {
                if(ans != nums.get(i)) {
                    ans = nums.get(i);
                    break;
                }
            }
        }

        System.out.println(ans);

        System.out.println(maxNum - minNum);

        br.close();
    }
    
}
