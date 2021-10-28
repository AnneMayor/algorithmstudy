import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main_10423 {

    public static ArrayList<ArrayList<PowerPlant> > powerPlantsList;
    public static ArrayList<Integer> powerPlantNums;
    public static boolean [] isVisited;

    static class PowerPlant implements Comparable<PowerPlant> {
        int num;
        int weight;

        public PowerPlant(int num, int weight) {
            this.num = num;
            this.weight = weight;
        }

        @Override
        public int compareTo(Main.PowerPlant p) {
            return this.weight - p.weight;
        }
    }

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] nmk = br.readLine().split(" ");

        int n = Integer.parseInt(nmk[0]);
        int m = Integer.parseInt(nmk[1]);
        int k = Integer.parseInt(nmk[2]);

        String [] powerPlants = br.readLine().split(" ");
        powerPlantsList = new ArrayList<>();
        for(int i = 0; i <= n; i++) {
            powerPlantsList.add(new ArrayList<>());
        }

        powerPlantNums = new ArrayList<>();
        for(int i = 0; i < k; i++) {
            powerPlantNums.add(Integer.parseInt(powerPlants[i]));
        }

        isVisited = new boolean[n+1];

        for(int i = 0; i < m; i++) {
            String [] uvw = br.readLine().split(" ");
            int u = Integer.parseInt(uvw[0]);
            int v = Integer.parseInt(uvw[1]);
            int w = Integer.parseInt(uvw[2]);

            powerPlantsList.get(u).add(new PowerPlant(v, w));
            powerPlantsList.get(v).add(new PowerPlant(u, w));
        }

        System.out.println(primSearch());

    }

    public static int primSearch() {
        int res = 0;

        PriorityQueue<PowerPlant> pq = new PriorityQueue<>();

        for(int i = 0; i < powerPlantNums.size(); i++) {
            int powerPlant = powerPlantNums.get(i);
            isVisited[powerPlant] = true;
            for(int j = 0; j < powerPlantsList.get(powerPlant).size(); j++) {
                PowerPlant connectedPosition = powerPlantsList.get(powerPlant).get(j);
                pq.add(connectedPosition);
            }
        }

        while(!pq.isEmpty()) {
            PowerPlant current = pq.poll();
            
            if(!isVisited[current.num]) {
                isVisited[current.num] = true;
                res += current.weight;

                for(int i = 0; i < powerPlantsList.get(current.num).size(); i++) {
                    PowerPlant next = powerPlantsList.get(current.num).get(i);
                    if(!isVisited[next.num]) {
                        pq.add(next);
                    }
                }
            }
        }

        return res;
    }    
}
