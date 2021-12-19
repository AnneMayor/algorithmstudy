import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main {

    public static ArrayList<ArrayList<Point> > map;
    public static Boolean[] isVisited;

    static class Point implements Comparable<Point>{
        int num;
        int usado;

        public Point(int num, int usado) {
            this.num = num;
            this.usado = usado;
        }

        @Override
        public int compareTo(Main.Point p) {
            return usado - p.usado;
        }
    }

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);

        map = new ArrayList<>();
        isVisited = new Boolean[n+1];

        for(int i = 0; i <= n; i++) {
            map.add(new ArrayList<>());
        }
        
        for(int i = 1; i < n; i++) {
            String [] pqr = br.readLine().split(" ");
            int p = Integer.parseInt(pqr[0]);
            int q = Integer.parseInt(pqr[1]);
            int r = Integer.parseInt(pqr[2]);

            map.get(p).add(new Point(q,r));
            map.get(q).add(new Point(p,r));
        }

        for(int i = 0; i < m; i++) {
            String [] kv = br.readLine().split(" ");
            int k = Integer.parseInt(kv[0]);
            int v = Integer.parseInt(kv[1]);

            Arrays.fill(isVisited, false);
            System.out.println(bfsSearch(v, k));
        }

    }

    public static int bfsSearch(int start, int k) {
        int count = 0;

        isVisited[start] = true;
        PriorityQueue<Point> q = new PriorityQueue<>();
        q.add(new Point(start, 0));

        while(!q.isEmpty()) {
            Point current = q.poll();
            isVisited[current.num] = true;
            if(current.usado == 0 || current.usado >= k) {
                if(current.usado >= k) count++;
                for(Point next : map.get(current.num)) {
                    int minUsado = current.usado == 0 ? next.usado : Math.min(current.usado, next.usado);
                    if(!isVisited[next.num]) {
                        q.add(new Point(next.num, minUsado));
                    }
                }
            }

        }

        return count;
    }
    
}
