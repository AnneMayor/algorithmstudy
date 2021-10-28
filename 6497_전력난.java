import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main_6497 {

    public static ArrayList<ArrayList<Village>> villages;
    public static boolean [] isVisited;

    static class Village implements Comparable<Village> {
        int num;
        int weight;

        public Village(int num, int weight) {
            this.num = num;
            this.weight = weight;
        }

        @Override
        public int compareTo(Main.Village v) {
            return this.weight - v.weight;
        }
    }

    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {

            String[] mn = br.readLine().split(" ");

            int m = Integer.parseInt(mn[0]);
            int n = Integer.parseInt(mn[1]);
            isVisited = new boolean[m+1];

            if (m == 0 && n == 0)
                break;

            villages = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                villages.add(new ArrayList<>());
            }

            Long totalWeightSum = 0L;
            for(int i = 0; i < n; i++) {
                String[] abw = br.readLine().split(" ");
                int a = Integer.parseInt(abw[0]);
                int b = Integer.parseInt(abw[1]);
                int w = Integer.parseInt(abw[2]);
                totalWeightSum += w;
                villages.get(a).add(new Village(b, w));
                villages.get(b).add(new Village(a, w));
            }

            System.out.println(totalWeightSum - primSearch(0));
        }

    }

    public static Long primSearch(int start) {
        Long minWeightSum = 0L;

        PriorityQueue<Village> pq = new PriorityQueue<>();

        for(int i = 0; i < villages.get(start).size(); i++) {
            Village v = villages.get(start).get(i);
            pq.add(v);
        }

        isVisited[start] = true;
        while(!pq.isEmpty()) {
            Village current = pq.poll();

            if(isVisited[current.num] == false) {
                isVisited[current.num] = true;
                minWeightSum += current.weight;

                for(int i = 0; i < villages.get(current.num).size(); i++) {
                    Village next = villages.get(current.num).get(i); 
                    if(!isVisited[next.num]) {
                        pq.add(next);
                    }
                }
            }
        }

        return minWeightSum;
    }

}
