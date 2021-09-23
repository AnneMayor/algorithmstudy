import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class Atcoder_Beginner_Contest_217_E {
    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int q = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        Queue<Integer> q1 = new LinkedList<>();

        for(int i = 0; i < q; i++) {
            String[] command = br.readLine().split(" ");
            int x = Integer.parseInt(command[0]);
            
            switch(x) {
                case 1:
                q1.add(Integer.parseInt(command[1]));
                break;
                case 2:
                if(!pq.isEmpty()) {
                    System.out.println(pq.poll());
                } else System.out.println(q1.poll());
                break;
                case 3:
                while(!q1.isEmpty()) {
                    pq.add(q1.poll());
                }
                break;
            }
        }

    }
}
