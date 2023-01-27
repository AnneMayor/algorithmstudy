import java.util.ArrayList;
import java.util.List;

public class Solution {
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        List<List<Integer> > nodes = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            nodes.addAll(new ArrayList<>());
        }

        for (int i = 0; i < edges.length; i++) {
            int[] edge = edges[i];

            nodes.get(edge[0]).add(edge[1]);
            nodes.get(edge[1]).add(edge[0]);
        }

        return minRecursiveSearchTime(0, nodes, hasApple, 0);
    }

    public int minRecursiveSearchTime(int current, List<List<Integer> > nodes, List<Boolean> hasApple, int parent) {
        int total = 0;

        for (int next : nodes.get(current)) {
            if (parent == next) continue;

            total += minRecursiveSearchTime(next, nodes, hasApple, current);
        }

        if (current != 0 && (hasApple.get(current) || total > 0)) {
            total += 2;
        }

        return total;
    }
}