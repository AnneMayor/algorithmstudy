import java.util.PriorityQueue;

public class LeetCode_RemoveCoveredIntervals {

    class Interval implements Comparable<Interval>{
        int start;
        int end;

        public Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(LeetCode_RemoveCoveredIntervals.Interval i) {
            if(this.start == i.start) return i.end - this.end;
            return this.start - i.start;
        }
    }

    public int removeCoveredIntervals(int[][] intervals) {
        
        int n = intervals.length;
        PriorityQueue<Interval> pq = new PriorityQueue<>();

        for(int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            pq.offer(new Interval(start, end));
        }

        int res = 0;

        Interval current = pq.poll();

        System.out.println("start: " + current.start + " , end: " + current.end);

        while(!pq.isEmpty()) {
            Interval next = pq.poll();
            if((current.start <= next.start) && (current.end >= next.end)) res++;
            else current = next;
        }

        return n - res;
    }
}
