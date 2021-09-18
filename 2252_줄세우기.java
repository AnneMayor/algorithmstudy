import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main_2252 {

    public static int [] result;
    public static int [] inDegree;
    public static ArrayList<ArrayList<Integer> > arr;

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);

        result = new int[n+1];
        inDegree = new int[n+1];

        Arrays.fill(result, 0);
        Arrays.fill(inDegree, 0);

        arr = new ArrayList<>();
        for(int i = 0; i <= n; i++) {
            arr.add(new ArrayList<>());
        }

        for(int i = 0; i < m; i++) {
            String [] ab = br.readLine().split(" ");
            int a = Integer.parseInt(ab[0]);
            int b = Integer.parseInt(ab[1]);

            arr.get(a).add(b);
            ++inDegree[b];
        }

        topologicalSearch(n);

        for(int i = 1; i <= n; i++) {
            System.out.print(result[i] + " ");
        }
        System.out.println();
    }

    public static void topologicalSearch(int n) {
        Queue<Integer> q = new LinkedList<Integer>();
        
        for(int i = 1; i <= n; i++) {
            if(inDegree[i] == 0) q.add(i);
        }

        for(int i = 1; i <= n; i++) {
            if(q.isEmpty()) {
                System.out.println(-1);
                return ;
            }

            int current = q.poll();
            result[i] = current;

            for(int j = 0; j < arr.get(current).size(); j++) {
                int next = arr.get(current).get(j);
                if(--inDegree[next] == 0) q.add(next);
            }
        }
    }
    
}
