import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main {

    public static ArrayList<ArrayList<Point> > map;
    public static int [] dist;
    
    static class Point implements Comparable<Point> {
        int dst;
        int weight;

        public Point() {}

        public Point(int dst, int weight) {
            this.dst = dst;
            this.weight = weight;
        }

        @Override
        public int compareTo(Point p) {
            return this.weight - p.weight;
        }
    }

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] ve = br.readLine().split(" ");
        int v = Integer.parseInt(ve[0]);
        int e = Integer.parseInt(ve[1]);
        int start = Integer.parseInt(br.readLine());

        map = new ArrayList<>();
        for(int i = 0; i <= v; i++) {
            map.add(new ArrayList<>());
        }

        dist = new int[v+1];
        Arrays.fill(dist, 10000000);

        for(int i = 0; i < e; i++) {
            String[] uvw = br.readLine().split(" ");
            int u = Integer.parseInt(uvw[0]);
            int uv = Integer.parseInt(uvw[1]);
            int w = Integer.parseInt(uvw[2]);
            map.get(u).add(new Point(uv, w));
        }

        dijstra(start);

        for(int i = 1; i <= v; i++) {
            if(dist[i] == 10000000) System.out.println("INF");
            else System.out.println(dist[i]);
        }
        
    }

    public static void dijstra(int start) {
        dist[start] = 0;
        PriorityQueue<Point> pq = new PriorityQueue<>();
        pq.add(new Point(start, 0));

        while(!pq.isEmpty()) {
            Point p = pq.poll();
            
            if(p.weight > dist[p.dst]) continue;

            for(int i = 0; i < map.get(p.dst).size(); i++) {
                int there = map.get(p.dst).get(i).dst;
                int cost = p.weight + map.get(p.dst).get(i).weight;

                if(dist[there] > cost) {
                    dist[there] = cost;
                    pq.add(new Point(there, cost));
                }
            }
        }
    }
}
