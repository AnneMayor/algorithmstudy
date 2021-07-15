import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;

public class Main {

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] weight;
        ArrayList<ArrayList<Integer> > graphs;
        PriorityQueue<Integer> pq;

        String nAndm = br.readLine();
        String[] nm = nAndm.split(" ");
        int n, m;
        n = Integer.parseInt(nm[0]);
        m = Integer.parseInt(nm[1]);

        weight = new int[n+1];

        pq = new PriorityQueue<>();

        graphs = new ArrayList<>();
        for(int i = 0; i < n+1; i++) {
            graphs.add(new ArrayList<>());
        }

        for(int i = 0; i < m; i++) {
            int a, b;
            String aAndb = br.readLine();
            String[] ab = aAndb.split(" ");
            a = Integer.parseInt(ab[0]);
            b = Integer.parseInt(ab[1]);
            weight[b]++;
            graphs.get(a).add(b);
        }

        for(int i = 1; i <= n; i++) {
            if(weight[i] == 0) {
                pq.offer(i);
            } 
        }

        while(!pq.isEmpty()) {
            int v = pq.poll();
            System.out.print(v + " ");
            for(int i = 0; i < graphs.get(v).size(); i++) {
                int child = graphs.get(v).get(i);
                weight[child]--;
                if(weight[child] == 0) {
                    pq.offer(child);
                }
            }
        }

        System.out.println();

        br.close();
    }
}
