public class LeetCode_GameOfLife {

    public int [] dx = {0, 0, -1, 1, -1, -1, 1, 1};
    public int [] dy = {-1, 1, 0, 0, -1, 1, -1, 1};
    public void gameOfLife(int[][] board) {
        int [][] nextGeneration = new int[board.length][board[0].length];

        int n = board.length, m = board[0].length;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cntOfAlive = 0;
                for(int k = 0; k < 8; k++) {
                    int nx = i + dx[k], ny = j + dy[k];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                    if(board[nx][ny] == 1) cntOfAlive++;
                }

                nextGeneration[i][j] = cntOfAlive;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 1 && nextGeneration[i][j] < 2) board[i][j] = 0;
                else if(board[i][j] == 1 && nextGeneration[i][j] > 3) board[i][j] = 0;
                else if(board[i][j] == 0 && nextGeneration[i][j] == 3) board[i][j] = 1;
            }
        }
    }
}
