import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Main_6118 {

    public static ArrayList<Integer> ans;
    public static ArrayList<Integer> [] map;
    public static boolean [] isVisited;
    public static Queue<Integer> q;
    public static int [] paths;

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);

        map = new ArrayList[n+1];

        for(int i = 0; i <= n; i++) {
            map[i] = new ArrayList<>();
        }

        for(int i = 0; i < m; i++) {
            String [] ab = br.readLine().split(" ");
            int a = Integer.parseInt(ab[0]);
            int b = Integer.parseInt(ab[1]);

            map[a].add(b);
            map[b].add(a);
        }
        
        int maxPath = 0;
        int loc = 0;
        paths = new int[n+1];

        q = new LinkedList<>();
        isVisited = new boolean[n+1];

        findPath(n);

        for(int p = 1; p <= n; p++) {
            if(maxPath < paths[p]) {
                maxPath = paths[p];
                loc = p;
            } else if(maxPath == paths[p]) {
                loc = Math.min(loc, p);
            }
        }

        int cnt = 0;
        for(int p = 2; p <= n; p++) {
            if(maxPath == paths[p]) cnt++;
        }

        System.out.println(loc + " " + maxPath + " " + cnt);
    }
    

    public static void findPath(int n) {
        isVisited[1] = true;
        q.add(1);

        int [] curPaths = new int[n+1];
        
        while(!q.isEmpty()) {
            int curPoint = q.poll();
            int curPath = curPaths[curPoint];

            paths[curPoint] = paths[curPoint] == 0 ? curPath : paths[curPoint];

            for(int i = 0; i < map[curPoint].size(); i++) {
                int next = map[curPoint].get(i);
                if(!isVisited[next]) {
                    isVisited[next] = true;
                    curPaths[next] = curPath + 1;
                    q.add(next);
                }
            }
        }

    }
}
