import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String...args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        int cnt = 1;
        int num = 1;
        int [][] board = new int[n][n];
        int startX = n / 2, startY = n / 2;
        int ansX = -1, ansY = -1;

        while(num < n * n) {
            // up
            for(int i = 0; i < cnt; i++) {
                if(num == m) {
                    ansX = startX;
                    ansY = startY;
                }
                board[startX--][startY] = num;
                num++;
            }

            if(num >= n * n) break;

            // right
            for(int i = 0; i < cnt; i++) {
                if(num == m) {
                    ansX = startX;
                    ansY = startY;
                }
                board[startX][startY++] = num;
                num++;
            }
            cnt++;
            if(num >= n * n) break;

            // down
            for(int i = 0; i < cnt; i++) {
                if(num == m) {
                    ansX = startX;
                    ansY = startY;
                }
                board[startX++][startY] = num;
                num++;
            }
            if(num >= n * n) break;

            // left
            for(int i = 0; i < cnt; i++) {
                if(num == m) {
                    ansX = startX;
                    ansY = startY;
                }
                board[startX][startY--] = num;
                num++;
            }
            cnt++;

            if(num >= n * n) break;
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                sb.append(String.valueOf(board[i][j]) + " ");
            }
            sb.append("\n");
        }

        ansX++;
        ansY++;

        sb.append(String.valueOf(ansX) + " " + String.valueOf(ansY));
        sb.append("\n");

        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}
