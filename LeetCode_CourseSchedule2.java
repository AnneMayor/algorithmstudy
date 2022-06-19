import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class LeetCode_CourseSchedule2 {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<Integer> answer = new ArrayList<>();

        int [] count = new int[numCourses];
        int [][] isLinked = new int[numCourses][numCourses];

        for(int [] course : prerequisites) {
            count[course[0]]++;
            isLinked[course[0]][course[1]] = 1;
            isLinked[course[1]][course[0]] = 1;
        }

        Queue<Integer> list = new LinkedList<>();

        for(int i = 0; i < numCourses; i++) {
            if(count[i] == 0) list.add(i);
        }

        while(!list.isEmpty()) {
            int current = list.poll();
            answer.add(current);

            for(int i = 0; i < numCourses; i++) {
                if(isLinked[current][i] == 1) {
                    count[i]--;
                    if(count[i] == 0) {
                        list.add(i);
                    }
                }
            }
        }

        int [] arrInt = {};

        if(answer.size() < numCourses) return arrInt;

        for(int i = 0; i < numCourses; i++) {
            arrInt[i] = answer.get(i);
        }

        return arrInt;
    }
}
