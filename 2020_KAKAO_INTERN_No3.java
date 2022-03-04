import java.util.Arrays;
import java.util.PriorityQueue;

public class Solution {

    public int [] dx = {-1, 0, 1, 0};
    public int [] dy = {0, -1, 0, 1};
    public int [] direction = {0, 1, 2, 3}; // 0: up, 1: left, 2: down, 3: right

    class Point implements Comparable<Point>{
        int x;
        int y;
        int direction;
        int cost;

        public Point(int x, int y, int direction, int cost) {
            this.x = x;
            this.y = y;
            this.direction = direction;
            this.cost = cost;
        }

        @Override
        public int compareTo(Solution.Point o) {
            return this.cost - o.cost;
        }
    }

    public int solution(int[][] board) {
        int n = board.length;
        int[][][] minExpense = new int[n][n][4];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                Arrays.fill(minExpense[i][j], Integer.MAX_VALUE);
            }
        }

        PriorityQueue<Point> pq = new PriorityQueue<>();

        pq.offer(new Point(0, 0, 0, 0));
        pq.offer(new Point(0, 0, 1, 0));
        pq.offer(new Point(0, 0, 2, 0));
        pq.offer(new Point(0, 0, 3, 0));

        for(int i = 0; i < 4; i++) {
            minExpense[0][0][i] = 0;
        }

        while(!pq.isEmpty()) {
            Point current = pq.poll();

            if(current.x == n-1 && current.y == n-1) break;

            for(int i = 0; i < 4; i++) {
                int nextX = current.x + dx[i];
                int nextY = current.y + dy[i];
                int nextDirection = direction[i];

                if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= n || board[nextX][nextY] == 1) continue;

                if(Math.abs(current.direction - nextDirection) == 2) continue;

                int nextCost = 0;
                if(current.direction == nextDirection) {
                    nextCost += 100;
                } else {
                    nextCost += 600;
                }

                nextCost += current.cost;
                
                if(minExpense[nextX][nextY][nextDirection] > nextCost) {
                    minExpense[nextX][nextY][nextDirection] = nextCost;
                    pq.offer(new Point(nextX, nextY, nextDirection, nextCost));
                }
            }
            
        }
        
        int res = Integer.MAX_VALUE;

        for(int i = 0; i < 4; i++) {
            res = Math.min(res, minExpense[n-1][n-1][i]);
        }
        
        return res;
    }
    
}
