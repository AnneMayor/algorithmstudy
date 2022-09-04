public class CrackingTheCodingInterview_Chapter1_ZeroMatrix {
    public void setZeros(int [][] matrix) {
        int n = matrix.length, m = matrix[0].length;

        boolean hasFirstRowZero = false;
        boolean hasFirstColZero = false;

        for(int i = 0; i < m; i++) {
            if(matrix[0][i] == 0) {
                hasFirstRowZero = true;
                break;
            }
        }

        for(int i = 0; i < n; i++) {
            if(matrix[i][0] == 0) {
                hasFirstColZero = true;
                break;
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // row
        for(int i = 1; i < n; i++) {
            if(matrix[i][0] == 0) {
                nullifyRow(matrix, i);
            }
        }

        // column
        for(int i = 1; i < m; i++) {
            if(matrix[0][i] == 0) {
                nullifyCol(matrix, i);
            }
        }

        // first row
        if(hasFirstRowZero) {
            for(int i = 0; i < m; i++) {
                nullifyRow(matrix, 0);
            }
        }

        // first column
        if(hasFirstColZero) {
            for(int i = 0; i < m; i++) {
                nullifyCol(matrix, 0);
            }
        }

    }

    public void nullifyRow(int [][] matrix, int index) {
        int m = matrix[0].length;
        for(int i = 0; i < m; i++) matrix[index][i] = 0;
    }

    public void nullifyCol(int [][] matrix, int index) {
        int n = matrix.length;
        for(int i = 0; i < n; i++) matrix[i][index] = 0;
    }

    public static void main(String... args) {
        CrackingTheCodingInterview_Chapter1_StringRotation sc = new CrackingTheCodingInterview_Chapter1_StringRotation();
        int [][] example = {{1, 1, 1, 1}, {1, 1, 0, 3}, {3, 4, 4, 0}};
        sc.setZeros(example);

        int n = example.length, m = example[0].length;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                System.out.print(example[i][j] + " ");
            }
            System.out.println();
        }
    }
}
