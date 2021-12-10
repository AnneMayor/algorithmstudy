import java.util.Comparator;
import java.util.PriorityQueue;

public class 프로그래머스_입국심사_withPriorityQueue {
    public long solution(int n, int[] times) {
        long answer = 0L;
        double vel = 0D;
        for(int time : times) vel += 1D / time;
        double expectedCompleteTime = n / vel;

        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparing(a -> a[0] + a[1]));

        for(int time : times) {
            Long count = (long) expectedCompleteTime / time;
            pq.offer(new long[]{count * time, Long.valueOf(time)});
            n -= count;
        }

        for(int i = 0; i < n; i++) {
            long[] currentStaff = pq.poll();
            currentStaff[0] += currentStaff[1];
            answer = currentStaff[0];
            pq.offer(currentStaff);
        }

        return answer;
    }
}