import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class LeetCode_SingleNumber {
    public int singleNumber(int[] nums) {
        Map<Integer, Integer> isTwice = new HashMap<>();
        for(int num : nums) {
            if(!isTwice.containsKey(num)) {
                isTwice.put(num, 1);                
            } else isTwice.put(num, isTwice.get(num) + 1);
        }

        int ans = 0;
        Set<Integer> ketSet = isTwice.keySet();
        for(int key : ketSet) {
            System.out.println(isTwice.get(key) + " , " + key);
            if(isTwice.get(key) <= 1) ans = key;
        }

        return ans;
    }
}
