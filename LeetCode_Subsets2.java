import java.util.ArrayList;
import java.util.List;

public class LeetCode_Subsets2 {

    // bitmask : O(N * 2 ^ N) Time | O(N * 2 ^ N) Space
    public List<List<Integer>> subsets(int[] nums) {
        int n = nums.length;
        List<List<Integer> > answer = new ArrayList<>();

        for(int i = 0; i < (1 << n); i++) {
            List<Integer> res = new ArrayList<>();
            for(int j = 0; j < n; j++) {
                
                if((i & (1 << j)) > 0) {
                    // System.out.println("i: " + i + " , j: " + j);
                    res.add(nums[j]);
                }
            }
            answer.add(new ArrayList<>(res));
        }

        return answer;
    }
}
