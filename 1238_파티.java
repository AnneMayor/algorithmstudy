import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main {

    // 이 문제의 핵심은 제자리로 돌아오는 케이스는 i -> j + j -> i 이런 식으로 단방향으로의 최단 거리 각각 구해서 더하면 된다!!!
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
        String [] nmx = br.readLine().split(" ");
        int n = Integer.parseInt(nmx[0]);
        int m = Integer.parseInt(nmx[1]);
        int x = Integer.parseInt(nmx[2]);

        dist = new int[n+1];

        map = new ArrayList<>();
        for(int i = 0; i <= n; i++) {
            map.add(new ArrayList<>());
        }

        for(int i = 0; i < m; i++) {
            String [] uvw = br.readLine().split(" ");
            int u = Integer.parseInt(uvw[0]);
            int v = Integer.parseInt(uvw[1]);
            int w = Integer.parseInt(uvw[2]);

            map.get(u).add(new Point(v, w));
        }

        int ans = -1;
        for(int i = 1; i <= n; i++) {
            int total = 0;
            dijstra(i, x);
            total += dist[x];
            dijstra(x, i);
            total += dist[i];
            ans = Math.max(ans, total);
        }

        System.out.println(ans);
    }
    

    public static void dijstra(int start, int end) {
        Arrays.fill(dist, 10000000);
        dist[start] = 0;
        PriorityQueue<Point> pq = new PriorityQueue<>();
        pq.add(new Point(start, 0));

        while(!pq.isEmpty()) {
            Point p = pq.poll();
            
            if(p.weight > dist[p.dst]) continue;
            if(p.dst == end) break;

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
