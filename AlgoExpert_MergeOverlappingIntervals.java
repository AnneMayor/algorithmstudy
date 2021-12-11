import java.util.*;

public class Program {

    public Stack<int []> mergeOverlappingIntervals(int[][] intervals) {
        Stack<int []> answer = new Stack<>();

        int [][] sortedIntervals = intervals.clone();
        Arrays.sort(sortedIntervals, (a, b) -> Integer.compare(a[0], b[0]));

        int n = intervals.length;
        for(int i = 0; i < n; i++) {
            if(answer.isEmpty()) {
                answer.push(new int[]{sortedIntervals[i][0], sortedIntervals[i][1]});
            } else {
                int [] prevInterval = answer.pop();
                if(prevInterval[1] < sortedIntervals[i][0]) {
                    answer.push(prevInterval);
                    answer.push(new int[]{sortedIntervals[i][0], sortedIntervals[i][1]});
                } else {
                    int nextEnd = Math.max(prevInterval[1], sortedIntervals[i][1]);
                    answer.push(new int[]{prevInterval[0], nextEnd});
                }
            }
        }

        return answer;
    }
}