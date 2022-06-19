import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class LeetCode_CourseSchedule3 {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses, (a, b) -> {
            if(a[1] == b[1]) return a[0] - b[0];
            return a[1] - b[1];
        });

        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());

        int prev = 0;
        for(int [] course : courses) {
            if(prev + course[0] <= course[1]) {
                pq.add(course[0]);
                prev += course[0];
            } 
            else if(pq.size() > 0 && course[0] < pq.peek()) {
                prev -= pq.poll();
                pq.add(course[0]);
                prev += course[0];
            }
        }


        return pq.size();
    }
}
