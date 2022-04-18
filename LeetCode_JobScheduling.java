import java.util.Arrays;

public class LeetCode_JobScheduling {

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int [][] arr = new int[startTime.length][3];

        int n = startTime.length;
        for(int i = 0; i < n; i++) {
            arr[i][0] = startTime[i]; arr[i][1] = endTime[i]; arr[i][2] = profit[i];
        }

        Arrays.sort(arr, (a, b) -> a[0] - b[0]);

        int [] memo = new int[n];

        Arrays.fill(memo, -1);

        return solve(memo, 0, arr);
    }
    
    public int solve(int [] memo, int index, int [][] arr) {
        if(index == arr.length) return 0;

        if(memo[index] != -1) return memo[index];

        int next = index + 1;
        while(next < arr.length && arr[index][1] > arr[next][0]) next++;

        return memo[index] = Math.max(arr[index][2]+solve(memo, next, arr), solve(memo, index+1, arr));
    }
}
