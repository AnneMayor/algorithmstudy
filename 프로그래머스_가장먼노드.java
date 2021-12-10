import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class 프로그래머스_가장먼노드 {
    public int[] currentDist;
    public ArrayList<ArrayList<Integer> > map;
    public int solution(int n, int[][] edge) {
        int answer = 0;

        currentDist = new int[n+1];

        Arrays.fill(currentDist, -1);

        map = new ArrayList<>();

        for(int i = 0; i <= n; i++) {
            map.add(new ArrayList<>());
        }

        for(int [] nodes : edge) {
            map.get(nodes[0]).add(nodes[1]);
            map.get(nodes[1]).add(nodes[0]);
        }

        int maxDist = bfsSearch(1, 0);

        System.out.println(maxDist);

        for(int i = 1; i <= n; i++) {
            if(maxDist == currentDist[i]) answer++;
        }


        // for(int dist : currentDist) System.out.print(dist + " ");
        System.out.println();


        return answer;
    }

    public int bfsSearch(int start, int dist) {
        int maxDist = 0;

        Queue<Integer> q = new LinkedList<>();

        q.offer(start);
        currentDist[start] = dist;

        while(!q.isEmpty()) {
            int currentNode = q.poll();
            int curDist = currentDist[currentNode];

            maxDist = Math.max(maxDist, curDist);
            
            for(int i = 0; i < map.get(currentNode).size(); i++) {
                int next = map.get(currentNode).get(i);
                if(currentDist[next] == -1) {
                    // System.out.println("next: " + next);
                    currentDist[next] = curDist + 1;
                    q.offer(next);
                }
            }
        }

        return maxDist;
    }
}
