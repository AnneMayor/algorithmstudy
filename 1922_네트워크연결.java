import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Main_1922 {

    static class Network implements Comparable<Network> {
        int a;
        int b;
        int c;

        public Network(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        @Override
        public int compareTo(Main.Network n) {
            return c - n.c;
        }
    }

    static class DisjointSet {
        int [] parent;
        int [] rank;

        public DisjointSet(int n) {
            parent = new int[n+1];
            rank = new int[n+1];
            for(int i = 1; i <= n; i++) {
                parent[i] = i;
            }

            Arrays.fill(rank, 1);
        }

        public int find(int u) {
            if(parent[u] == u) return u;
            return parent[u] = find(parent[u]);
        }

        public void merge(int u, int v) {
            u = find(u);
            v = find(v);
            if(u == v) return ;
            if(rank[u] > rank[v]) {
                parent[v] = u;
            }
            else {
                parent[u] = v;
            }
            if(rank[u] == rank[v]) rank[u]++;
        }
    }

    public static ArrayList<Network> graphs;

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        graphs = new ArrayList<>();

        for(int i = 0; i < m; i++) {
            String [] abc = br.readLine().split(" ");
            int a = Integer.parseInt(abc[0]);
            int b = Integer.parseInt(abc[1]);
            int c = Integer.parseInt(abc[2]);

            graphs.add(new Network(a, b, c));
        }

        Collections.sort(graphs);

        System.out.println(kruskal(n));
    }

    public static int kruskal(int n) {
        int ans = 0;

        DisjointSet group = new DisjointSet(n+1);

        for(int i = 0; i < graphs.size(); i++) {
            int u = graphs.get(i).a;
            int v = graphs.get(i).b;
            int weight = graphs.get(i).c;

            if(group.find(u) == group.find(v)) continue;

            ans += weight;
            group.merge(u, v);
        }

        return ans;
    }
    
}
