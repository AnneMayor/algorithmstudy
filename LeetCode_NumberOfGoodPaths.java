import java.util.*;

class UnionFind {
    private int[] parent;
    private int[] rank;
    public UnionFind(int n) {
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        rank = new int[n];
    }

    public int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    public void union_set(int u, int v) {
        int pu = find(u), pv = find(v);

        if (pu == pv) return ;
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else  if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
}


public class Solution {
    public int numberOfGoodPaths(int[] vals, int[][] edges) {
        List<List<Integer> > nodes = new ArrayList<>();

        int n = vals.length;

        for (int i = 0; i < n; i++) {
            nodes.add(new ArrayList<>());
        }

        for (int [] edge : edges) {
            nodes.get(edge[0]).add(edge[1]);
            nodes.get(edge[1]).add(edge[0]);
        }

        Map<Integer, List<Integer>> valueGroup = new TreeMap<>();

        for (int i = 0; i < n; i++) {
            if (!valueGroup.containsKey(vals[i])) {
                valueGroup.put(vals[i], new ArrayList<>());
            }

            valueGroup.get(vals[i]).add(i);
        }

        UnionFind uf = new UnionFind(n);

        int goodPaths = 0;

        for (int value : valueGroup.keySet()) {
            for (int node : valueGroup.get(value)) {
                for (int neighbor : nodes.get(node)) {
                    if (vals[node] >= vals[neighbor]) {
                        uf.union_set(node, neighbor);
                    }
                }
            }

            Map<Integer, Integer> sizeGroup = new HashMap<>();

            for (int node : valueGroup.get(value)) {
                sizeGroup.put(uf.find(node), sizeGroup.getOrDefault(uf.find(node), 0) + 1);
            }

            for (int key : sizeGroup.keySet()) {
                int paths = sizeGroup.get(key);
                goodPaths += paths * (paths + 1) / 2;
            }

        }

        return goodPaths;
    }
}