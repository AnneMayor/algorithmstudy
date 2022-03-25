import java.util.List;

public class HackerRank_FormingMagicSquare {

    public static int formingMagicSquare(List<List<Integer>> s) {
        int [][][] magicSquare = {{{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}, {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}}, {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}, 
                                  {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}, {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}, {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
                                  {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}}, {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}}};

        int cost = Integer.MAX_VALUE;
        int n = s.size();

        for(int i = 0; i < 8; i++) {
            int totalDiff = 0;

            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k ++) {
                    totalDiff += Math.abs(s.get(j).get(k) - magicSquare[i][j][k]);
                }
            }

            cost = Math.min(cost, totalDiff);
        }

        return cost;
    }
}
