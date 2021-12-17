import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class 프로그래머스_기능개발 {
    public ArrayList<Integer> solution(int[] progresses, int[] speeds) {
        ArrayList<Integer> answer =  new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        int n = progresses.length;
        for(int i = 0; i < n; i++) {
            int left = 100 - progresses[i];
            int day = (left % speeds[i] == 0 ? left / speeds[i] : left / speeds[i] + 1);
            q.add(day);
        }
        
        int countOfWorks = 0;
        int curWorkDay = 0;
        while(!q.isEmpty()) {
            if(countOfWorks <= 0) {
                curWorkDay = q.poll();
                countOfWorks++;
            } else {
                int nextDay = q.peek();
                if(curWorkDay >= nextDay) {
                    q.poll();
                    countOfWorks++;
                } else {
                    answer.add(countOfWorks);
                    countOfWorks = 0;
                }
            }
        }

        if(countOfWorks >= 0) answer.add(countOfWorks);

        return answer;
    }
}
