import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Main_2606 {

    public static boolean [] isVisited;
    public static ArrayList<ArrayList<Integer> > map;

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        map = new ArrayList<>();

        for(int i = 0; i <= n; i++) {
            map.add(new ArrayList<>());
        }

        for(int i = 0; i < m; i++) {
            String [] ab = br.readLine().split(" ");
            int a = Integer.parseInt(ab[0]);
            int b = Integer.parseInt(ab[1]);

            map.get(a).add(b);
            map.get(b).add(a);
        }

        System.out.println(getInfectedComputer(n));
    }

    public static int getInfectedComputer(int n) {
        int res = 0;

        isVisited = new boolean[n+1];
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(1);
        isVisited[1] = true;

        while(!q.isEmpty()) {
            int curComp = q.poll();

            for(int next : map.get(curComp)) {
                if(!isVisited[next]) {
                    isVisited[next] = true;
                    q.add(next);
                    res += 1;
                }
            }
        }
        
        return res;
    }
}
