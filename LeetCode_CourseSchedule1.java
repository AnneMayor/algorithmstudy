import java.util.LinkedList;
import java.util.Queue;

public class LeetCode_CourseSchedule1 {

    // topological sort
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int [] count = new int[numCourses];
        int [][] isLinked = new int[numCourses][numCourses];
        
        for(int[] course : prerequisites) {
            count[course[0]]++;
            isLinked[course[0]][course[1]] = 1;
            isLinked[course[1]][course[0]] = 1;
        }

        Queue<Integer> list = new LinkedList<>();

        for(int i = 0; i < numCourses; i++) {
            if(count[i] == 0) list.add(i);
        }

        int totalCheckCourses = 0;

        while(!list.isEmpty()) {
            int current = list.poll();
            totalCheckCourses++;

            for(int i = 0; i < numCourses; i++) {
                if(isLinked[current][i] == 1) {
                    count[i]--;
                    if(count[i] == 0) list.add(i);
                }
            }
        }

        return totalCheckCourses == numCourses;
    }
}
