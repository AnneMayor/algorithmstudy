import java.util.LinkedList;
import java.util.Scanner;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.MaximizeAction;

public class Main {

    public static LinkedList<LinkedList<Integer> > graphs;
    public static boolean[] isVisited;
    public static void main(String...args) {

        Scanner sc = new Scanner(System.in);
        graphs = new LinkedList<>();

        int n, m;
        n = sc.nextInt(); m = sc.nextInt();
        for(int i = 0; i < n; i++) {
            graphs.add(new LinkedList<>());
        }
        isVisited = new boolean[n+1];
        
        for(int i = 0; i < m; i++) {
            int a, b;
            a = sc.nextInt();
            b = sc.nextInt();
            a--; b--;
            if(a > b) {
                graphs.get(b).add(a);
            } else {
                graphs.get(a).add(b);
            }
        }

        int ans = search(0, 0, n);
        ans *= 2;
        ans = (ans < n ? (ans+1) : ans);
        System.out.println(ans);

        sc.close();
    }

    public static int search(int u, int cnt, int n) {
        if(u >= n) return cnt;
        if(isVisited[u]) return search(u+1, cnt, n);
        int res = 0;
        for(int i = 0; i < graphs.get(u).size(); i++) {
            int v = graphs.get(u).get(i);
            if(!isVisited[v]) {
                isVisited[v] = true;
                res = Math.max(res, search(u+1, cnt+1, n));
                isVisited[v] = false;
            }
        }

        return Math.max(res, search(u+1, cnt, n));
    }
}
