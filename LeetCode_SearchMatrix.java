public class LeetCode_SearchMatrix {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;
        int startIdx = 0;

        for(int i = 0; i < n; i++) {
            if(matrix[i][m-1] == target) {
                return true;
            }

            if(matrix[i][m-1] > target) {
                startIdx = i;
                break;
            }
        }

        if(startIdx < 0) return false;

        for(int i = 0; i < m; i++) {
            if(matrix[startIdx][i] == target) return true;
        }

        return false;
    }
}
