import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class 위상정렬_topologicalSearch_With_Queue {

    public static final int MAX = 100;
    public static int [] result = new int[MAX];
    public static ArrayList<ArrayList<Integer> > arr;
    public static int [] inDegree = new int[MAX];

    public static void main(String... args) {
        
        Arrays.fill(result, 0);
        Arrays.fill(inDegree, 0);

        // 그래프: https://m.blog.naver.com/ndb796/221236874984 참조
        int n = 7;
        arr = new ArrayList<>();

        for(int i = 0; i < n+1; i++) {
            arr.add(new ArrayList<>());
        }

        arr.get(1).add(2);
        inDegree[2]++;
        arr.get(1).add(5);
        inDegree[5]++;
        arr.get(2).add(3);
        inDegree[3]++;
        arr.get(3).add(4);
        inDegree[4]++;
        arr.get(4).add(6);
        inDegree[6]++;
        arr.get(5).add(6);
        inDegree[6]++;
        arr.get(6).add(7);
        inDegree[7]++;
        topologicalSort(n);
    }

    public static void topologicalSort(int n) {

        // 위상정렬 알고리즘: 시간복잡도 = O(V+E)
        Queue<Integer> q = new LinkedList<>();

        for(int i = 1; i <= n; i++) {
            if(inDegree[i] == 0) q.add(i);
        }

        for(int i = 1; i <= n; i++) {
            if(q.isEmpty()) {
                System.out.println("Occurs Graph Cycle!");
                return ;
            }

            int num = q.poll();
            result[i] = num;
            
            for(int j = 0; j < arr.get(num).size(); j++) {
                int next = arr.get(i).get(j);
                if(--inDegree[next] == 0) {
                    q.add(next);
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            System.out.print(result[i] + " ");
        }
        System.out.println();
    }
    
}
