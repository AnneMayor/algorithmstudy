public class LeetCode_Rotate90degree {
    public void rotate(int[][] matrix) {
        int n = matrix.length;

        for(int i = 0; i < n / 2; i++) {
            int first = i;
            int last = n - 1 - i;

            for(int j = first; j < last; j++) {
                int offset = j - first;

                int top = matrix[first][j];

                matrix[first][j] = matrix[last-offset][first];

                matrix[last-offset][first] = matrix[last][last-offset];

                matrix[last][last-offset] = matrix[j][last];

                matrix[j][last] = top;
            }
        }
        

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String...args) {
        int matrix[][] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
        CrackingTheCodingInterview_Chapter1_ZeroMatrix sc = new CrackingTheCodingInterview_Chapter1_ZeroMatrix();
        sc.rotate(matrix);
    }
}
