/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class LeetCode_VerticalOrderTraversalOfABinaryTree {

    class Node implements Comparable<Node>{
        int row;
        int val;

        public Node(int row, int val) {
            this.row = row;
            this.val = val;
        }

        @Override
        public int compareTo(LeetCode_Equation.Node that) {
            if(this.row == that.row) return this.val - that.val;
            return this.row - that.row;
        }
    }

    private int minCol = Integer.MAX_VALUE;
    private int maxCol = Integer.MIN_VALUE;
    private Map<Integer, List<Node> > nodes;
    
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        nodes = new HashMap<>();
        recursiveSearch(root, 0, 0);

        List<List<Integer> > ans = new ArrayList<>();

        int currentAnsIndex = 0;
        // System.out.println("min: " + minCol + " , max: " + maxCol);
        for(int i = minCol; i <= maxCol; i++) {
            List<Node> res = nodes.get(i);
            // System.out.println(res.size());
            Collections.sort(res);
            ans.add(new ArrayList<>());

            for(Node node : res) {
                ans.get(currentAnsIndex).add(node.val);
            }
            currentAnsIndex++;
        }

        return ans;
    }

    public void recursiveSearch(TreeNode root, int row, int col) {
        if(root == null) return ;

        minCol = Math.min(minCol, col);
        maxCol = Math.max(maxCol, col);

        if(nodes.get(col) == null) {
            List<Node> newNodeList = new ArrayList<>();
            newNodeList.add(new Node(row, root.val));
            nodes.put(col, newNodeList);
        } else {
            nodes.get(col).add(new Node(row, root.val));
        }

        recursiveSearch(root.left, row+1, col-1);
        recursiveSearch(root.right, row+1, col+1);
    }
    
}
