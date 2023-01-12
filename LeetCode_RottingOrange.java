import java.util.LinkedList;
import java.util.Queue;

public class LeetCode_RottingOrange {

    public int[] dx = {-1, 1, 0, 0};
    public int[] dy = {0, 0, -1, 1};

    static class Orange {
        int x;
        int y;
        int minute;

        public Orange(int x, int y, int minute) {
            this.x = x;
            this.y = y;
            this.minute = minute;
        }
    }

    public int orangesRotting(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        Queue<Orange> q = new LinkedList<>();

        int numOfFreshOrange = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.add(new Orange(i, j, 0));
                } else if(grid[i][j] == 1) numOfFreshOrange++;
            }
        }


        int res = 0;
        while(!q.isEmpty()) {
            Orange current = q.poll();

            res = current.minute;
            for(int i = 0; i < 4; i++) {
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

                if(grid[nx][ny] == 1) {
                    numOfFreshOrange -= 1;
                    grid[nx][ny] = 2;
                    q.add(new Orange(nx, ny, current.minute + 1));
                }
            }
        }

        if(numOfFreshOrange <= 0) return res;
        return -1;
    }
}
