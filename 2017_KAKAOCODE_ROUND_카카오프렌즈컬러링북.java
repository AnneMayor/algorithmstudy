import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    boolean [][] isChecked;
    int numberOfArea = 0;
    int maxSizeOfOneArea = 0;
    int [] dx = {-1, 1, 0, 0};
    int [] dy = {0, 0, -1, 1};

    class Point {
        int x;
        int y;
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public int[] solution(int m, int n, int[][] picture) {
        
        isChecked = new boolean[m][n];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!isChecked[i][j] && picture[i][j] > 0) {
                    numberOfArea++;
                    bfsSearch(i, j, picture, m, n);
                }
            }
        }

        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }

    public void bfsSearch(int x, int y, int[][] picture, int m, int n) {
        int area = picture[x][y];
        int cntOfArea = 1;
        isChecked[x][y] = true;

        Queue<Point> q = new LinkedList<>();
        q.add(new Point(x, y));

        while(!q.isEmpty()) {
            Point current = q.poll();
            int curX = current.x;
            int curY = current.y;
            int curArea = picture[curX][curY];

            for(int i = 0; i < 4; i++) {
                int nx = curX + dx[i];
                int ny = curY + dy[i];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

                if(picture[nx][ny] == curArea && !isChecked[nx][ny]) {
                    isChecked[nx][ny] = true;
                    cntOfArea++;
                    q.add(new Point(nx, ny));
                }
            }
        }

        maxSizeOfOneArea = Math.max(maxSizeOfOneArea, cntOfArea);
    }
}