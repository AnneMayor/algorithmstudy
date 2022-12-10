public class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> res = new ArrayList<>();

        if (graph.length == 0 || graph[0].length == 0) return res;

        List<Integer> sources = new ArrayList<>();
        sources.add(0);
        allPathsFromZeroToN(graph, 0, graph.length-1, sources, res);

        return res;
    }

    public void allPathsFromZeroToN(int[][] graph, int start, int end, List<Integer> sources, List<List<Integer>> res) {
        if(start >= end) {
            res.add(new ArrayList<>(sources));
            return ;
        }

        for(int next : graph[start]) {
            sources.add(next);
            allPathsFromZeroToN(graph, next, end, sources, res);
            sources.remove(sources.size()-1);
        }
    }
}