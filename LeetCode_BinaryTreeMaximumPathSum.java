public class Solution {

    private int maxPathSum;

    public int maxPathSum(TreeNode root) {
        maxPathSum = root.val;
        helper(root);
        return maxPathSum;
    }

    public int helper(TreeNode node) {
        if(node == null) return 0;

        int left = helper(node.left);
        int right = helper(node.right);

        int max = Math.max(Math.max(node.val, Math.max(node.val + left, node.val + right)), left + node.val + right);
        
        maxPathSum = Math.max(maxPathSum, max);

        return Math.max(node.val, Math.max(node.val + left, node.val + right));
    }
    
}
