import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class C {
    public int[] answer = new int[2];
    public int[][] map;
    public int curX, curY;
    public boolean[][] isVisited;
    public ArrayList<Point> people;

    public int[] dx = {-1, 1, 0, 0};
    public int[] dy = {0, 0, -1, 1};

    class Point {
        int x;
        int y;
        int dist;

        public Point(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }

    public int[] solution(int n, int k) {

        map = new int[n][n];
        curX = 0; curY = 0;
        map[curX][curY] = 1;
        people = new ArrayList<>();
        people.add(new Point(curX, curY, 0));

        for(int i = 2; i <= n*n; i++) {
            isVisited = new boolean[n][n];
            bfsSearch(n);
            map[curX][curY] = i;
            people.add(new Point(curX, curY, 0));

            if(i == k) break;
        }

        answer[0] = curX + 1;
        answer[1] = curY + 1;

        return answer;
    }

    public void bfsSearch(int n) {
        int maxDist = 0;
        int maxX = 0;
        int maxY = 0;

        Queue<C.Point> q = new LinkedList<>();
        for(Point p : people) {
            isVisited[p.x][p.y] = true;
            q.add(p);
        }

        while(!q.isEmpty()) {
            Point current = q.poll();
            int currentX = current.x;
            int currentY = current.y;
            int currentDist = current.dist;

            if(currentDist > maxDist) {
                maxX = currentX;
                maxY = currentY;
                maxDist = currentDist;
            } else if(currentDist == maxDist) {
                if(currentY < maxY) {
                    maxX = currentX;
                    maxY = currentY;
                } else if(currentY == maxY) {
                    if(currentX < maxX) {
                        maxX = currentX;
                        maxY = currentY;
                    }
                }
            }

            for(int i = 0; i < 4; i++) {
                int nextX = currentX + dx[i];
                int nextY = currentY + dy[i];
                int nextDist = currentDist + 1;

                if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= n) continue;

                if(!isVisited[nextX][nextY] && map[nextX][nextY] == 0) {
                    isVisited[nextX][nextY] = true;
                    q.add(new Point(nextX, nextY, nextDist));
                }
            }
        }

        curX = maxX;
        curY = maxY;
    }
}
