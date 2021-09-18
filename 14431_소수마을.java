import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main_14431 {

    public static ArrayList<Point> arr;
    public static ArrayList<ArrayList<Dist> > map;
    public static int [] dist;
    public static final int MAX = 987654321;
    public static boolean [] primeNums = new boolean[50000];

    static class Point {

        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Dist implements Comparable<Dist> {
        int dist;
        int position;

        public Dist(int dist, int position) {
            this.dist = dist;
            this.position = position;
        }

        @Override
        public int compareTo(Main_14431.Dist o) {
            return this.dist - o.dist;
        }
    }

    public static void main(String...args) throws IOException {

        arr = new ArrayList<>();
        map = new ArrayList<>();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] sa = br.readLine().split(" ");
        int sx = Integer.parseInt(sa[0]);
        int sy = Integer.parseInt(sa[1]);
        int ax = Integer.parseInt(sa[2]);
        int ay = Integer.parseInt(sa[3]);

        int n = Integer.parseInt(br.readLine());

        arr.add(new Point(sx, sy));
        arr.add(new Point(ax, ay));

        dist = new int[n+2];
        Arrays.fill(dist, MAX);
        Arrays.fill(primeNums, true);

        findAllPrimes();

        for(int i = 0; i < n+2; i++) {
            map.add(new ArrayList<>());
        }

        for(int i = 1;i <= n; i++) {
            String [] x = br.readLine().split(" ");
            int xx = Integer.parseInt(x[0]);
            int xy = Integer.parseInt(x[1]);
            arr.add(new Point(xx, xy));
        }

        for(int i = 0; i < n+2; i++) {
            Point p1 = arr.get(i);
            for(int j = i+1; j < n+2; j++) {
                Point p2 = arr.get(j);
                if(isPrimeNum(p1.x, p1.y, p2.x, p2.y)) {
                    map.get(i).add(new Dist(getPrimeDistance(p1.x, p1.y, p2.x, p2.y), j));
                    map.get(j).add(new Dist(getPrimeDistance(p1.x, p1.y, p2.x, p2.y), i));
                }
            }
        }

        dijstra();
        // BFS 방식으로 풀었을 경우, 메모리 초과 에러가 난다.
        // bfs(n+2);

        // for(int i = 0; i <= 20; i++) {
        //     System.out.print(primeNums[i] + " ");
        // }
        // System.out.println();

        // for(int i = 0; i < n+2; i++) {
        //     System.out.print(dist[i] + " ");
        // }
        // System.out.println();

        if(dist[1] == MAX) System.out.println(-1);
        else System.out.println(dist[1]);
    }

    public static void dijstra() {
        PriorityQueue<Dist> pq = new PriorityQueue<>();
        dist[0] = 0;
        pq.add(new Dist(0, 0));

        while(!pq.isEmpty()) {
            Dist d = pq.poll();
            int currentDist = d.dist;
            int currentPosition = d.position;

            if(dist[currentPosition] < currentDist) continue;

            for(int i = 0; i < map.get(currentPosition).size(); i++) {
                Dist n = map.get(currentPosition).get(i);
                int nextDist = currentDist + n.dist;
                int nextPosition = n.position;
                if(dist[nextPosition] > nextDist) {
                    dist[nextPosition] = nextDist;
                    pq.add(new Dist(nextDist, nextPosition));
                }
            }
        }
    }

    public static void bfs(int n) {
        Queue<Dist> q = new LinkedList<>();
        boolean [] isVisited = new boolean[n];
        Arrays.fill(isVisited, false);

        dist[0] = 0;
        isVisited[0] = true;
        q.add(new Dist(0, 0));

        while(!q.isEmpty()) {
            Dist d = q.poll();
            int curPosition = d.position;
            int curDist = d.dist;

            dist[curPosition] = Math.min(dist[curPosition], curDist);

            for(int i = 0; i < map.get(curPosition).size(); i++) {
                Dist np = map.get(curPosition).get(i);
                int nextPosition = np.position;
                int nextDist = np.dist;

                if(!isVisited[nextPosition]) {
                    isVisited[nextPosition] = true;
                    q.add(new Dist(curDist + nextDist, nextPosition));
                }
            }
        }

    }

    public static boolean isPrimeNum(int cx, int cy, int nx, int ny) {
        int dist = (int) Math.sqrt((cx-nx) * (cx-nx) + (cy - ny) * (cy - ny));
        boolean res = primeNums[dist];
        return res;
    }

    // 시간복잡도가 향상된 에라토스테네스의 체 알고리즘
    // public static boolean isPrimeNum(int cx, int cy, int nx, int ny) {
    //     int dist = (int) Math.sqrt((cx-nx) * (cx-nx) + (cy - ny) * (cy - ny));
    //     if(dist < 2) return false;
    //     for(int i = 2; i * i < dist; i++) {
    //         if(dist % i == 0) return false;
    //     }
    //     return true;
    // }

    public static int getPrimeDistance(int cx, int cy, int nx, int ny) {
        return (int) Math.sqrt((cx-nx) * (cx-nx) + (cy - ny) * (cy - ny));
    }

    public static void findAllPrimes() {

        primeNums[0] = false;
        primeNums[1] = false;

        for(int i = 2; i <= 5000; i++) {
            for(int j = i*i; j <= 5000; j+=i) {
                primeNums[j] = false;
            }
        }
    }
    
}
