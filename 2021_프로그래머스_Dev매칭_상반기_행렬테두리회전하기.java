import java.util.ArrayList;

public class Solution {
    public ArrayList<Integer> solution(int rows, int columns, int[][] queries) {

        int [][] matrix = new int[rows+1][columns+1];

        for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= columns; j++) {
                matrix[i][j] = (i-1)*columns + j;
            }
        }

        ArrayList<Integer> answer = new ArrayList<>();

        for(int cnt = 0; cnt < queries.length; cnt++) {
            int x1, x2, y1, y2;
            x1 = queries[cnt][0];
            y1 = queries[cnt][1];
            x2 = queries[cnt][2];
            y2 = queries[cnt][3];

            int row = x2-x1+1;
            int col = y2-y1+1;

            int minVal = 999999999;

            int [][] temp = new int[row][col];
            for(int x = 0; x < row; x++) {
                for(int y = 0; y < col; y++) {
                    temp[x][y] = matrix[x+x1][y+y1];
                }
            }

            // y1 -> y2
            for(int y = 0; y < col-1; y++) {
                temp[0][y+1] = matrix[x1][y+y1];
                minVal = Math.min(minVal, temp[0][y+1]);    
            }

            // x1 -> x2
            for(int x = 0; x < row-1; x++) {
                temp[x+1][col-1] = matrix[x+x1][y2];
                minVal = Math.min(minVal, temp[x+1][col-1]);
            }
            
            // y2 -> y1
            for(int y = col-1; y > 0; y--) {
                temp[row-1][y-1] = matrix[x2][y+y1];
                minVal = Math.min(minVal, matrix[x2][y+y1]);
            }

            // x2 -> x1
            for(int x = row-1; x > 0; x--) {
                temp[x-1][0] = matrix[x+x1][y1];
                minVal = Math.min(minVal, temp[x-1][0]);
            }

            for(int x = 0; x < row; x++) {
                for(int y = 0; y < col; y++) {
                    matrix[x+x1][y+y1] = temp[x][y];
                }
            }

            // System.out.println("--------------------");
            // for(int x = 0; x < row; x++) {
            //     for(int y = 0; y < col; y++) {
            //         System.out.print(temp[x][y] + " ");
            //     }
            //     System.out.println();
            // }
            // System.out.println("--------------------");

            answer.add(minVal);

        }

        return answer;
    }
}