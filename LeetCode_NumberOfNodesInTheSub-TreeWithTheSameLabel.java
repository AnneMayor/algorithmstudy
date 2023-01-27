public class Solution {
    public int[] countSubTrees(int n, int[][] edges, String labels) {
        int[] ans = new int[n];
        List<List<Integer> > nodes = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            nodes.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            nodes.get(edge[0]).add(edge[1]);
            nodes.get(edge[1]).add(edge[0]);
        }

        boolean[] visited = new Boolean[n];

        countSubTrees(0, visited, nodes, labels, ans);

        return ans;
    }

    public int[] countSubTrees(int current, boolean[] visited, List<List<Integer> > nodes, String labels, int[] ans) {

        int[] alphabets = new int[26];
        visited[current] = true;
        alphabets[labels.charAt(current) - 'a'] = 1;

        for (int next : nodes.get(current)) {
            if (current == next) continue;
            if(!visited[next]) {
                int[] childCount = countSubTrees(next, visited, nodes, labels, ans);

                for (int i = 0; i < 26; i++) {
                    alphabets[i] += childCount[i];
                }
            }
        }

        ans[current] = alphabets[labels.charAt(current) - 'a'];

        return alphabets;
    }
}