import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class Main_14621 {

    public static ArrayList<ArrayList<University> > universities;
    public static int [] groupOfUniv;
    public static boolean [] isVisited;

    static class University implements Comparable<University> {
        int num;
        int weight;

        public University(int num, int weight) {
            this.num = num;
            this.weight = weight;
        }


        @Override
        public int compareTo(Main.University u) {
            return this.weight - u.weight;
        }
    }

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);

        groupOfUniv = new int[n+1];
        isVisited = new boolean[n+1];
        universities = new ArrayList<>();

        for(int i = 0; i <= n; i++) {
            universities.add(new ArrayList<>());
        }

        String [] mw = br.readLine().split(" ");
        
        for(int i = 0; i < n; i++) {
            if(mw[i].equals("M")) {
                groupOfUniv[i+1] = 1;
            } else {
                groupOfUniv[i+1] = 2;
            }
        }

        for(int i = 0; i < m; i++) {
            String [] uvd = br.readLine().split(" ");
            int u = Integer.parseInt(uvd[0]);
            int v = Integer.parseInt(uvd[1]);
            int d = Integer.parseInt(uvd[2]);

            universities.get(u).add(new University(v, d));
            universities.get(v).add(new University(u, d));
        }

        System.out.println(primSearch(n));

    }
    
    public static int primSearch(int n) {
        int res = 0;

        PriorityQueue<University> pq = new PriorityQueue<>();

        for(int i = 0; i < universities.get(1).size(); i++) {
            University next = universities.get(1).get(i);
            if(groupOfUniv[1] != groupOfUniv[next.num]) {
                pq.add(next);
            }
        }

        isVisited[1] = true;
        while(!pq.isEmpty()) {
            University current = pq.poll();

            if(!isVisited[current.num]) {
                isVisited[current.num] = true;

                res += current.weight;
    
                for(int i = 0; i < universities.get(current.num).size(); i++) {
                    University next = universities.get(current.num).get(i);
                    if(groupOfUniv[next.num] != groupOfUniv[current.num] && !isVisited[next.num]) {
                        pq.add(next);
                    }
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            if(!isVisited[i]) {
                res = -1;
                break;
            }
        }

        return res;
    }
}
