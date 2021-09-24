import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.TreeSet;

public class Atcoder_Beginner_Contest_218_D {

    static class Point implements Comparable<Point>{
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Point o) {
            if(x == o.x) return y - o.y;
            return x - o.x;
        }
    }

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        
        TreeSet<Point> tree = new TreeSet<>();
        Point [] pList = new Point [n+1];
        for(int i = 0; i < n; i++) {
            String [] xy = br.readLine().split(" ");
            int x = Integer.parseInt(xy[0]);
            int y = Integer.parseInt(xy[1]);
            Point p = new Point(x, y);
            tree.add(p);
            pList[i] = p;
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(pList[i].x != pList[j].x && pList[i].y != pList[j].y) {
                    if(tree.contains(new Point(pList[i].x, pList[j].y)) && tree.contains(new Point(pList[j].x, pList[i].y))) ans++;
                }
            }
        }

        System.out.println(ans/2);
    }
}
