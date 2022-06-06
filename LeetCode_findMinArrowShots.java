import java.util.ArrayList;
import java.util.Arrays;

public class LeetCode_findMinArrowShots {

    public int findMinArrowShots(int[][] points) {

        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));

        int cnt = 1;
        int best_endpoint = points[0][1];

        int n = points.length;
        
        for(int i = 1; i < n; i++) {
            if(best_endpoint < points[i][0]) {
                cnt++;
                best_endpoint = points[i][1];
            }
        }
        
        return cnt;
    }
    
}
