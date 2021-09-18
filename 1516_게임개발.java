import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main {

    public static Long [] result;
    public static int [] inDegree;
    public static ArrayList<ArrayList<Integer> > arr;
    public static Long [] time;

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        result = new Long[n+1];
        inDegree = new int[n+1];
        time = new Long[n+1];

        Arrays.fill(result, 0L);
        Arrays.fill(inDegree, 0);
        Arrays.fill(time, 0L);

        arr = new ArrayList<>();

        for(int i = 0; i <= n; i++) {
            arr.add(new ArrayList<>());
        }
        
        for(int i = 1; i <= n; i++) {
            String [] buildings = br.readLine().split(" ");
            time[i] = Long.parseLong(buildings[0]);
            for(int j = 1; j < buildings.length; j++) {
                if(buildings[j].equals("-1")) break;
                int pre = Integer.parseInt(buildings[j]);
                arr.get(pre).add(i);
                inDegree[i]++;
            }
        }

        topologicalSort(n);

        for(int i = 1; i <= n; i++) {
            System.out.println(result[i]);
        }

    }

    public static void topologicalSort(int n) {
        PriorityQueue<Building> pq = new PriorityQueue<>();

        for(int i = 1; i <= n; i++) {
            if(inDegree[i] == 0) {
                pq.add(new Building(time[i], i));
            }
        }

        // while(!pq.isEmpty()) {
        //     System.out.println(pq.poll().time);
        // }

        for(int i = 1; i <= n; i++) {
            if(pq.isEmpty()) {
                return ;
            }

            Building current = pq.poll();
            result[current.num] += current.time;

            for(int j = 0; j < arr.get(current.num).size(); j++) {
                int next = arr.get(current.num).get(j);
                if(--inDegree[next] == 0) pq.add(new Building(current.time + time[next],  next));
            }
        }
    }

    static class Building implements Comparable<Building> {
        int num;
        Long time;

        public Building(Long time, int num) {
            this.num = num;
            this.time = time;
        }

        @Override
        public int compareTo(Main.Building o) {
            return this.time.intValue() - o.time.intValue();
        }
    }
}
