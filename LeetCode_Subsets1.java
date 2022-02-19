import java.util.ArrayList;
import java.util.List;

public class LeetCode_Subsets1 {
    public List<List<Integer> > answer;
    public List<List<Integer>> subsets(int[] nums) {
        int n = nums.length;
        answer = new ArrayList<>();

        subset(0, n, new ArrayList<>(), nums);
        
        return answer;
    }

    public void subset(int idx, int n, ArrayList<Integer> temp, int [] nums) {
        if(idx >= n) {
            answer.add(new ArrayList<>(temp));
            return ;
        }

        temp.add(nums[idx]);
        subset(idx+1, n, temp, nums);
        temp.remove(temp.size() - 1);
        subset(idx+1, n, temp, nums);
    }

}
