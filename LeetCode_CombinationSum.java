import java.util.ArrayList;
import java.util.List;

public class LeetCode_CombinationSum {

    public List<List<Integer> > answer;
    public List<List<Integer>> combinationSum(int[] candidates, int target) {

        answer = new ArrayList<>();
        int n = candidates.length;
        combination(0, 0, n, candidates, target, new ArrayList<>());

        return answer;
    }


    public void combination(int currentSum, int currentIdx, int n, int [] candidates, int target, List<Integer> temp) {
        if(currentSum >= target) {
            if(currentSum == target) {
                // for(int num : temp) System.out.print(num + " ");
                // System.out.println();
                List<Integer> res = new ArrayList<>(temp);
                answer.add(res);
            }
            return ;
        }
        
        for(int i = currentIdx; i < n; i++) {
            temp.add(candidates[i]);
            combination(currentSum+candidates[i], i, n, candidates, target, temp);
            temp.remove(temp.size()-1);
        }
    }
}
