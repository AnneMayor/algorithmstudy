import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.PriorityQueue;

public class Main_13209 {

    public static ArrayList<ArrayList<Integer> > map;
    public static Long block;
    public static boolean [] isVisited;
    public static Long [] cities;
    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= T; tc++) {
            String [] nk = br.readLine().split(" ");
            Long n = Long.parseLong(nk[0]);
            Long k = Long.parseLong(nk[1]);

            cities = new Long[1000005];

            map = new ArrayList<>();

            for(int i = 0; i <= n; i++) {
                map.add(new ArrayList<>());
            }

            Long left = 0L;
            Long right = 0L;

            String [] population = br.readLine().split(" ");
            for(int i = 0; i < n; i++) {    
                cities[i+1] = Long.parseLong(population[i]);
                left = Math.max(left, cities[i+1]);
                right += cities[i+1];
            }

            for(int i = 1; i < n; i++) {
                String [] connect = br.readLine().split(" ");
                int s = Integer.parseInt(connect[0]);
                int e = Integer.parseInt(connect[1]);

                map.get(s).add(e);
                map.get(e).add(s);
            }

            Long ans = 0L;

            isVisited = new boolean[1000005];

            while(left <= right) {
                Long mid = left + right >> 1;
                block = 0L;
                Arrays.fill(isVisited, false);
                parametricSearch(1, mid);
                if(block <= k) {
                    right = mid-1;
                    ans = mid;
                } else {
                    left = mid+1;
                }
            }

            System.out.println(ans);

        }
    }

    public static Long parametricSearch(int idx, Long totalSum) {
        isVisited[idx] = true;
        PriorityQueue<Long> pq = new PriorityQueue<>(Collections.reverseOrder());
        Long sum = 0L;
        Long val = 0L;

        for(int i = 0; i < map.get(idx).size(); i++) {
            int next = map.get(idx).get(i);
            if(isVisited[next]) continue;
            val = parametricSearch(next, totalSum);
            sum += val;
            pq.add(val);
        }

        while(!pq.isEmpty() && sum + cities[idx] > totalSum) {
            block++;
            sum -= pq.poll();
        }

        return sum + cities[idx];
    }
}