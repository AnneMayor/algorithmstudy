import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class LeetCode_NonOverlappingIntervals {

    static class Interval implements Comparable<Interval> {
        int start;
        int end;

        public Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Solution.Interval i) {
            if(this.start == i.start) return this.end - i.end;
            return this.start - i.start;
        }
    }

    public int eraseOverlapIntervals(int[][] intervals) {
        List<Interval> intervalList = new ArrayList<>();

        for(int [] interval : intervals) {
            intervalList.add(new Interval(interval[0], interval[1]));
        }

        Collections.sort(intervalList);

        int ans = 0;

        int prevStart = Integer.MIN_VALUE, prevEnd = Integer.MIN_VALUE;
        for(Interval i : intervalList) {
            if(prevEnd <= i.start) {
                prevStart = i.start;
                prevEnd = i.end;
            } else {
                ans++;
                if(prevEnd > i.end) {
                    prevStart = i.start;
                    prevEnd = i.end;
                }
            }
        }

        return ans;
    }
    
}
