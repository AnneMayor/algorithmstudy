import java.util.*;

public class Solution {
    static class Interval implements Comparable {
        private int start;
        private int end;

        public Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }

    @Override
        public int compareTo(Object next) {
            return this.start - ((Interval) next).start;
        }

    public int start() {
            return start;
        }

    public int end() {
            return end;
        }
    }

    public int[][] insert(int[][] intervals, int[] newInterval) {

        List<Interval> list = new ArrayList<>();

        for (int[] interval : intervals) {
            list.add(new Interval(interval[0], interval[1]));
        }

        list.add(new Interval(newInterval[0], newInterval[1]));

        Collections.sort(list);

        Deque<Interval> st = new LinkedList<>();
        st.add(list.remove(0));

        while (!list.isEmpty()) {
            Interval interval = st.pollLast();
            Interval next = list.remove(0);
            Interval nextInterval = interval;

            if (interval.end() >= next.start() && interval.end() < next.end()) {
                nextInterval = new Interval(interval.start(), next.end());
            }

            if (interval.end() < next.start()) {
                st.addLast(interval);
                nextInterval = new Interval(next.start(), next.end());
            }

            st.addLast(nextInterval);
        }

        int[][] ans = new int[st.size()][2];

        int idx = 0;
        while (!st.isEmpty()) {
            Interval interval = st.pollFirst();
            ans[idx][0] = interval.start();
            ans[idx][1] = interval.end();

            idx++;
        }

        return ans;
    }
}