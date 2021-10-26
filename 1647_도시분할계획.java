import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main_1647 {

    public static ArrayList<ArrayList<Point> > graphs;
    public static boolean [] isVisited;

    static class Point implements Comparable<Point> {
        int v;
        int e;

        public Point(int v, int e) {
            this.v = v;
            this.e = e;
        }

        @Override
        public int compareTo(Main.Point p) {
            return e - p.e;
        }
    }

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);

        graphs = new ArrayList<>();
        isVisited = new boolean[n+1];

        Arrays.fill(isVisited, false);

        for(int i = 0; i <= n; i++) {
            graphs.add(new ArrayList<>());
        }

        for(int i = 0; i < m; i++) {
            String [] abc = br.readLine().split(" ");
            int a = Integer.parseInt(abc[0]);
            int b = Integer.parseInt(abc[1]);
            int c = Integer.parseInt(abc[2]);
            
            graphs.get(a).add(new Point(b, c));
            graphs.get(b).add(new Point(a, c));
        }

        System.out.println(prim());
        
    }

    public static int prim() {
        int res = 0;
        int maxWeight = -1;

        PriorityQueue<Point> pq = new PriorityQueue<>();

        for(int i = 0; i < graphs.get(1).size(); i++) {
            pq.add(new Point(graphs.get(1).get(i).v, graphs.get(1).get(i).e));
        }

        isVisited[1] = true;
        while(!pq.isEmpty()) {
            Point current = pq.poll();

            if(isVisited[current.v] == false) {
                isVisited[current.v] = true;
                res += current.e;
                maxWeight = Math.max(maxWeight, current.e);

                for(int i = 0; i < graphs.get(current.v).size(); i++) {
                    Point next = graphs.get(current.v).get(i);

                    if(isVisited[next.v] == false) {
                        pq.add(new Point(next.v, next.e));
                    }

                }
            }
        }

        return res - maxWeight;
    }
    
}
