import java.util.HashMap;
import java.util.Map;

public class LeetCode_NumPairsDivisibleBy60 {
    public int numPairsDivisibleBy60(int[] time) {

        int ans = 0;

        Map<Integer, Integer> times = new HashMap<>();

        for(int t : time) {
            int remain = t % 60;
            int other = remain == 0 ? 0 : 60 - remain;
            ans += times.getOrDefault(other, 0);
            times.put(remain, times.getOrDefault(remain, 0) + 1); 
        }

        return ans;
    }
}
