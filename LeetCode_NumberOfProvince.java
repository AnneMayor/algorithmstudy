public class LeetCode_NumberOfProvince {
    public int [] parent;
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        parent = new int[n];

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        int ans = n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(isConnected[i][j] == 1) {
                    int firstParent = find(i);
                    int secondParent = find(j);
                    
                    if(firstParent != secondParent) {
                        ans--;
                        parent[firstParent] = secondParent;
                    }
                }
            }
        }

        return ans;
    }

    public int find(int node) {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
}
