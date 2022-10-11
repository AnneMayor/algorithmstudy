import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.TreeMap;

public class LeetCode_TheSkylineProblems {

    static class Point implements Comparable<Point>{
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(LeetCode_DecodeWays.Point o) {
            if(this.x == o.x) return o.y - this.y;
            return this.x - o.x;
        }
    }

    public List<List<Integer>> getSkyline(int[][] buildings) {
        List<Point> buildingPoints = new ArrayList<>();
        List<List<Integer> > res = new ArrayList<>();

        for(int [] building : buildings) {
            buildingPoints.add(new Point(building[0], building[2]));
            buildingPoints.add(new Point(building[1], -building[2]));
        }

        Collections.sort(buildingPoints);
        TreeMap<Integer, Integer> treeMap  = new TreeMap<>();

        int prev = 0;
        treeMap.put(0, 1);

        for(Point p : buildingPoints) {
            if(p.y > 0) {
                treeMap.put(p.y, treeMap.getOrDefault(p.y, 0) + 1);
            } else {
                int count = treeMap.get(-p.y);
                if(count == 1) treeMap.remove(-p.y);
                else treeMap.put(-p.y, count - 1);
            }

            int current = treeMap.lastKey();
            if(prev != current) {
                res.add(Arrays.asList(p.x, current));
                prev = current;
            }
        }

        return res;
    }
}
