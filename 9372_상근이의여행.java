import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
public class Main_9372 {
    
    public static class Point {
        int a, b;

        public Point(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    public static class DisjointSet {

        public static int[] parent;
        public static int[] rank;

        public DisjointSet() {
            parent = new int[1005];
            rank = new int[1005];
            
            for(int i = 0; i < 1005; i++) {
                parent[i] = i;
            }

            for(int i = 0; i < 1005; i++) {
                rank[i] = 1;
            }
        }

        void merge(int u, int v) {
            u = find(u);
            v = find(v);
            if(u == v) return ;
            if(rank[u] > rank[v]) {
                parent[v] = u;
            } else {
                parent[u] = v;
            }
            if(rank[u] == rank[v]) rank[v]++; 
        }

        int find(int u) {
            if(u == parent[u]) return u;
            return parent[u] = find(parent[u]);
        }

    }

    public static void main(String...args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        for(int tc = 1; tc <= T; tc++) {

            int n, m;
            n = sc.nextInt();
            m = sc.nextInt();

            ArrayList<Point> g = new ArrayList<>();

            for(int i = 0; i < m; i++) {
                int a = sc.nextInt();
                int b = sc.nextInt();

                g.add(new Point(a, b));
            }
            
            System.out.println(kruskal(g));
        }
    }

    public static int kruskal(ArrayList<Point> g) {
        int result = 0;

        DisjointSet group = new DisjointSet();

        for(int i = 0; i < g.size(); i++) {
            int u = g.get(i).a, v = g.get(i).b;
            if(group.find(u) == group.find(v)) continue;
            group.merge(u, v);
            result += 1;
        }

        return result;
    }
}
