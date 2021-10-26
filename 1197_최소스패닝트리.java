import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;


public class Main_1197 {

    static class Point {
        int p;
        Long w;

        public Point(int p, Long w) {
            this.p = p;
            this.w = w;
        }

    }

    public static ArrayList<ArrayList<Point> > graphs;
    public static int [] parent;
    public static Long [] minWeight;
    public static boolean [] isVisited;

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] ve = br.readLine().split(" ");

        int v = Integer.parseInt(ve[0]);
        int e = Integer.parseInt(ve[1]);

        graphs = new ArrayList<>();

        parent = new int[v+1];
        minWeight = new Long[v+1];
        isVisited = new boolean[v+1];

        Arrays.fill(minWeight, 2147483647L);
        Arrays.fill(parent, -1);
        Arrays.fill(isVisited, false);

        for(int i = 0; i <= v; i++) {
            graphs.add(new ArrayList<>());
        }

        for(int i = 0; i < e; i++) {
            String [] abc = br.readLine().split(" ");
            int a = Integer.parseInt(abc[0]);
            int b = Integer.parseInt(abc[1]);
            Long c = Long.parseLong(abc[2]);

            graphs.get(a).add(new Point(b, c));
            graphs.get(b).add(new Point(a, c));
        }

        System.out.println(prim(v));
        
    }


    public static Long prim(int v) {
        Long res = 0L;

        minWeight[1] = 0L;
        parent[1] = 0;
        for(int i = 1; i <= v; i++) {
            int u = -1;

            for(int j = 1; j <= v; j++) {
                if(!isVisited[j] && (u == -1 || minWeight[u] > minWeight[j])) {
                    u = j;
                }
            }

            isVisited[u] = true;
            res += minWeight[u];

            for(int j = 0; j < graphs.get(u).size(); j++) {
                int next = graphs.get(u).get(j).p;
                Long nextWeight = graphs.get(u).get(j).w;

                if(!isVisited[next] && minWeight[next] > nextWeight) {
                    parent[next] = u;
                    minWeight[next] = nextWeight;
                }
            }
        }

        return res;
    }
    
}
