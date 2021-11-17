import java.util.Collections;
import java.util.PriorityQueue;

// 구간의 최대값을 구하기 위해선 끝나는 시간 + 999ms < 시작시간 로직과 우선순위 큐를 활용하여 끝나는 시간의 마지막 로그에서부터 탐색해와야 한다!

public class Solution {
    public int solution(String[] lines) {
        int answer = 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int cnt = 0;
        for(int i = lines.length - 1; i >= 0; i--) {
            String[] logs = lines[i].split(" ");
            String[] time = logs[1].split(":");
            int hour = Integer.parseInt(time[0]) * 60 * 60 * 1000;
            int min = Integer.parseInt(time[1]) * 60 * 1000;
            double sec = Double.parseDouble(time[2])* 1000;
            int finishTime = hour + min + (int) sec;
            double takenTime = Double.parseDouble(logs[2].substring(0, logs[2].length()-1)) * 1000;
            
            cnt++;

            int startTime = finishTime - (int) takenTime + 1;
            pq.add(startTime);

            while(!pq.isEmpty()) {
                if(finishTime + 999 < pq.peek()) {
                    cnt--;
                    pq.poll();
                } else break;
            }

            answer = Math.max(answer, cnt);
        }
        return answer;
    }
}
