import java.util.PriorityQueue;

public class 프로그래머스_더맵게 {
    
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for(long scov : scoville) pq.add(scov);
        while(pq.peek() < K) {
            answer++;

            if(pq.size() < 2) {
                if(pq.peek() < K) answer = -1;
                break;
            }
            Long firstFood = pq.poll();
            Long secondFood = pq.poll();

            Long newScoville = firstFood + secondFood * 2;
            pq.add(newScoville);
        }

        return answer;
    }
    
}
