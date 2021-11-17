import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

    static class Range implements Comparable<Range> {
        int start;
        int end;

        public Range(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Range r) {
            return start - r.start;
        }
    }

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        ArrayList<Range> ranges = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            String[] points = br.readLine().split(" ");
            ranges.add(new Range(Integer.parseInt(points[0]), Integer.parseInt(points[1])));
        }

        Collections.sort(ranges);

        int ans = 0;
        for(int i = 0; i < ranges.size(); i++) {
            int cnt = 0;
            for(int j = i+1; j < ranges.size(); j++) {
                int startFirst = ranges.get(i).start;
                int endFirst = ranges.get(i).end;
                int startSecond = ranges.get(j).start;
                int endSecond = ranges.get(j).end;

                if(startFirst <= startSecond && endFirst >= endSecond) cnt++;
            }

            ans = Math.max(ans, cnt);
        }

        System.out.println(ans);
    }
}