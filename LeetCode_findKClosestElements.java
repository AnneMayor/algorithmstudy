import java.util.ArrayList;
import java.util.List;

public class LeetCode_findKClosestElements {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int startIdx = 0;

        int n = arr.length;

        for(; startIdx < n - k; ) {
            if(Math.abs(arr[startIdx]-x) > Math.abs(arr[startIdx+k]-x)) {
                startIdx++;
            } else if(Math.abs(arr[startIdx]-x) == Math.abs(arr[startIdx+k]-x)) {
                if(arr[startIdx] == arr[startIdx+k]) startIdx++;
                else break;
            } else break;
        }

        List<Integer> ans = new ArrayList<>();
        for(int count = 0; count < k; count++) {
            ans.add(arr[startIdx+count]);
        }

        return ans;
    }
}