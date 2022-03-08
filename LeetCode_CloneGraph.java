import java.util.List;

/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

public class LeetCode_CloneGraph {
  
    public Node [] visited;
    public Node cloneGraph(Node node) {
        if(node == null) return null;
        visited = new Node[101];
        Arrays.fill(visited, null);
        Node clone = new Node(node.val);
        dfs(node, clone);

        return clone;
    }
    
    public void dfs(Node node, Node clone) {

        visited[clone.val] = clone;

        for(Node neighbor : node.neighbors) {
            if(visited[neighbor.val] == null) {
                Node n = new Node(neighbor.val);
                clone.neighbors.add(n);
                dfs(neighbor, n);
            } else {
                clone.neighbors.add(visited[neighbor.val]);
            }
        }
    }  
    
}
