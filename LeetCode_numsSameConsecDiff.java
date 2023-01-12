import java.util.ArrayList;
import java.util.List;

public class LeetCode_numsSameConsecDiff {

    public int[] numsSameConsecDiff(int n, int k) {

        List<Integer> res = new ArrayList<>();
        
        for(int i = 1; i <= 9; i++) {
            recursiveSearch(i, i, 1, k, n, res);
        }

        int[] result = new int[res.size()];
        int idx = 0;
        for(int value : res) {
            result[idx++] = value;
        }

        return result;
    }

    public void recursiveSearch(int num, int sum, int idx, int k, int n, List<Integer> res) {
        if(idx >= n) {
            res.add(sum);
            return;
        }

        int nextNum = num + k;
        if(nextNum <= 9) {
            recursiveSearch(nextNum, (sum * 10) + nextNum, idx+1, k, n, res);
        }

        nextNum = num - k;
        if(k != 0 && nextNum >= 0) {
            recursiveSearch(nextNum, (sum * 10) + nextNum, idx+1, k, n, res);
        }
    }
}
