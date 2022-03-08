import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {


    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        
        int [][] numberBoard = new int[n][3];
        for(int i = 0; i < n; i++) {
            String[] numberRow = br.readLine().split(" ");
            for(int j = 0; j < 3; j++) {
                numberBoard[i][j] = Integer.parseInt(numberRow[j]);
            }
        }

        int [][] maxDp = new int[n][3];
        int [][] minDp = new int[n][3];
        maxDp[0][0] = numberBoard[0][0]; maxDp[0][1] = numberBoard[0][1]; maxDp[0][2] = numberBoard[0][2];
        minDp[0][0] = numberBoard[0][0]; minDp[0][1] = numberBoard[0][1]; minDp[0][2] = numberBoard[0][2];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                switch (j) {
                    case 0:
                        maxDp[i][j] = numberBoard[i][j] + Math.max(maxDp[i-1][j], maxDp[i-1][j+1]);
                        minDp[i][j] = numberBoard[i][j] + Math.min(minDp[i-1][j], minDp[i-1][j+1]);
                        break;
                    case 1:
                        maxDp[i][j] = numberBoard[i][j] + Math.max(Math.max(maxDp[i-1][j], maxDp[i-1][j+1]), maxDp[i-1][j-1]);
                        minDp[i][j] = numberBoard[i][j] + Math.min(Math.min(minDp[i-1][j], minDp[i-1][j+1]), minDp[i-1][j-1]);
                        break;

                    case 2:
                        maxDp[i][j] = numberBoard[i][j] + Math.max(maxDp[i-1][j], maxDp[i-1][j-1]);
                        minDp[i][j] = numberBoard[i][j] + Math.min(minDp[i-1][j], minDp[i-1][j-1]);
                        break;
                }
            }
        }

        // System.out.println("--------------");

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < 3; j++) {
        //         System.out.print(maxDp[i][j] + " ");
        //     }
        //     System.out.println();
        // }

        // System.out.println("--------------");

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < 3; j++) {
        //         System.out.print(minDp[i][j] + " ");
        //     }
        //     System.out.println();
        // }

        int maxValue = Integer.MIN_VALUE, minValue = Integer.MAX_VALUE;

        for(int i = 0; i < 3; i++) {
            maxValue = Math.max(maxValue, maxDp[n-1][i]);
            minValue = Math.min(minValue, minDp[n-1][i]);
        }

        System.out.println(maxValue + " " + minValue);
    }
}
